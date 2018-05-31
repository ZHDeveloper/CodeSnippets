//
//  UIGestureRecognizer+CategoryKit.m
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import "UIGestureRecognizer+CategoryKit.h"
#import <objc/runtime.h>


@interface UIGestureRecognizerBlockTarget: NSObject

@property (nonatomic, copy) void (^block)(id sender);

- (id)initWithBlock:(void (^)(id sender))block;
- (void)invoke:(id)sender;

@end

@implementation UIGestureRecognizerBlockTarget

- (id)initWithBlock:(void (^)(id sender))block{
    self = [super init];
    if (self) {
        _block = [block copy];
    }
    return self;
}

- (void)invoke:(id)sender {
    if (_block) _block(sender);
}

@end

@implementation UIGestureRecognizer (CategoryKit)

- (instancetype)initWithActionBlock:(void (^)(id sender))block {
    self = [self init];
    [self addActionBlock:block];
    return self;
}

- (void)addActionBlock:(void (^)(id sender))block {
    UIGestureRecognizerBlockTarget *target = [[UIGestureRecognizerBlockTarget alloc] initWithBlock:block];
    [self addTarget:target action:@selector(invoke:)];
    NSMutableArray *targets = [self blockTargets];
    [targets addObject:target];
}

- (void)removeAllActionBlocks {
    NSMutableArray *targets = [self blockTargets];
    [targets enumerateObjectsUsingBlock:^(id target, NSUInteger idx, BOOL *stop) {
        [self removeTarget:target action:@selector(invoke:)];
    }];
    [targets removeAllObjects];
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
