//
//  UIBarButtonItem+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (CategoryKit)

@property (nullable, nonatomic, copy) void (^actionBlock)(UIBarButtonItem *sender);

@end
