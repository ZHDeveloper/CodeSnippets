//
//  UIDevice+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (CategoryKit)

@property (nonatomic, readonly) double osVersion;

@property (nonatomic, readonly) BOOL isPad;

@property (nonatomic, readonly) BOOL isSimulator;

@property (nonatomic, readonly) BOOL isJailbroken;

@property (nonatomic, readonly) BOOL canMakePhoneCalls;

/// The device's machine model.  e.g. "iPhone6,1" "iPad4,6"
@property (nonatomic, readonly) NSString *machineModel;

@end
