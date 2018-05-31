//
//  UIApplication+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIApplication (CategoryKit)

@property (nullable, nonatomic, readonly) NSString *bundleId;

@property (nullable, nonatomic, readonly) NSString *displayName;

@property (nullable, nonatomic, readonly) NSString *version;

@property (nullable, nonatomic, readonly) NSString *buildVersion;

@property (nonatomic, readonly) int64_t memoryUsage;

@property (nonatomic, readonly) float cpuUsage;

@end
