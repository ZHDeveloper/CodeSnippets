//
//  NSString+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSString (CategoryKit)

@property (nonatomic, readonly) NSString *md5String;

- (NSString *)base64EncodedString;

+ (nullable NSString *)stringWithBase64EncodedString:(NSString *)base64EncodedString;

- (NSString *)stringByURLEncode;

- (NSString *)stringByURLDecode;

- (CGSize)sizeForFont:(UIFont *)font size:(CGSize)size mode:(NSLineBreakMode)lineBreakMode;

- (CGFloat)widthForFont:(UIFont *)font;

- (CGFloat)heightForFont:(UIFont *)font width:(CGFloat)width;

@end
