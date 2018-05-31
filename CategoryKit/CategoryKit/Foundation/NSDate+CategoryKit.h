//
//  NSDate+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (CategoryKit)

@property (nonatomic, readonly) NSInteger year;
@property (nonatomic, readonly) NSInteger month;
@property (nonatomic, readonly) NSInteger day;
@property (nonatomic, readonly) NSInteger hour;
@property (nonatomic, readonly) NSInteger minute;
@property (nonatomic, readonly) NSInteger second;

/// 纳秒
@property (nonatomic, readonly) NSInteger nanosecond;

/// < Weekday component (1~7, first day is based on user setting)
@property (nonatomic, readonly) NSInteger weekday;

@property (nonatomic, readonly) NSInteger weekOfMonth;
@property (nonatomic, readonly) NSInteger weekOfYear;

@property (nonatomic, readonly) NSInteger quarter;

/// 闰月
@property (nonatomic, readonly) BOOL isLeapMonth;
/// 闰年
@property (nonatomic, readonly) BOOL isLeapYear;

@property (nonatomic, readonly) BOOL isToday;
@property (nonatomic, readonly) BOOL isYesterday;

- (NSDate *)dateByAddingYears:(NSInteger)years;

- (NSDate *)dateByAddingMonths:(NSInteger)months;

- (NSDate *)dateByAddingWeeks:(NSInteger)weeks;

- (NSDate *)dateByAddingDays:(NSInteger)days;

- (NSDate *)dateByAddingHours:(NSInteger)hours;

- (NSDate *)dateByAddingMinutes:(NSInteger)minutes;

- (NSDate *)dateByAddingSeconds:(NSInteger)seconds;

- (NSString *)stringWithFormat:(NSString *)format;

+ (NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format;

@end
