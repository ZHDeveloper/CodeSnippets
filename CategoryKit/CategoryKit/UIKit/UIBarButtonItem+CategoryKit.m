//
//  UIBarButtonItem+CategoryKit.m
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import "UIBarButtonItem+CategoryKit.h"
#import <objc/runtime.h>

static void *block_key = &block_key;

@interface UIBarButtonItemBlockTarget: NSObject

@property (nullable, nonatomic, copy) void (^block)(UIBarButtonItem *);

- (void)invoke:(id)sender;

@end

@implementation UIBarButtonItemBlockTarget

- (instancetype)initWith:(void (^)(id))block {
    if ([super init]) {
        _block = [block copy];
    }
    return self;
}

- (void)invoke:(id)sender {
    if (self.block) self.block(sender);
}

@end

@implementation UIBarButtonItem (CategoryKit)

- (void)setActionBlock:(void (^)(UIBarButtonItem *))actionBlock {
    
    UIBarButtonItemBlockTarget *target = [[UIBarButtonItemBlockTarget alloc] initWith:actionBlock];
    
    objc_setAssociatedObject(self, block_key, target, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    [self setTarget:target];
    
    [self setAction:@selector(invoke:)];
}

- (void (^)(UIBarButtonItem *))actionBlock {
    
    UIBarButtonItemBlockTarget *target = objc_getAssociatedObject(self, block_key);
    
    return target.block;
}

@end
