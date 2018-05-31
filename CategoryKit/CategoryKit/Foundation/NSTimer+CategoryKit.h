//
//  NSTimer+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSTimer (CategoryKit)

/// 在当前线程的runloop将timer添加的default模式下
+ (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)seconds block:(void (^)(NSTimer *timer))block repeats:(BOOL)repeats;

/// 创建timer，需要手动添加到runloop
+ (NSTimer *)timerWithTimeInterval:(NSTimeInterval)seconds block:(void (^)(NSTimer *timer))block repeats:(BOOL)repeats;

@end
