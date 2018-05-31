//
//  UIControl+CategoryKit.m
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import "UIControl+CategoryKit.h"
#import <objc/runtime.h>

@interface UIControlBlockTarget: NSObject

@property (nullable, nonatomic, copy) void (^block)(UIControl *);

- (void)invoke:(id)sender;

@end

@implementation UIControlBlockTarget

- (instancetype)initWith:(void (^)(UIControl *))block {
    if ([super init]) {
        _block = [block copy];
    }
    return self;
}

- (void)invoke:(id)sender {
    if (self.block) self.block(sender);
}

@end

@interface UIControl ()

@property (nonatomic,readonly) NSMutableArray *blockTargets;

@end

@implementation UIControl (CategoryKit)

- (void)addBlock:(void (^)(UIControl *))block forControlEvents:(UIControlEvents)controlEvents {
    
    UIControlBlockTarget *target = [[UIControlBlockTarget alloc] initWith:block];
    
    [self addTarget:target action:@selector(invoke:) forControlEvents:controlEvents];
    
    [self.blockTargets addObject:target];
}

- (void)setBlock:(void (^)(UIControl *))block forControlEvents:(UIControlEvents)controlEvents {
    
    [self removeAllTargets];
    
    [self addBlock:block forControlEvents:controlEvents];
}

- (void)removeAllTargets {
    [[self allTargets] enumerateObjectsUsingBlock: ^(id object, BOOL *stop) {
        [self removeTarget:object action:NULL forControlEvents:UIControlEventAllEvents];
    }];
    [self.blockTargets removeAllObjects];
}

- (NSMutableArray *)blockTargets {
    
    NSMutableArray *targets = objc_getAssociatedObject(self, _cmd);
    
    if (!targets) {
        targets = [NSMutableArray array];
        objc_setAssociatedObject(self, _cmd, targets, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    
    return targets;
}

@end
