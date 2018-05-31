//
//  UIControl+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIControl (CategoryKit)

- (void)addBlock:(void (^)(UIControl *sender))block forControlEvents:(UIControlEvents)controlEvents;

- (void)setBlock:(void (^)(UIControl *sender))block forControlEvents:(UIControlEvents)controlEvents;

- (void)removeAllTargets;

@end
