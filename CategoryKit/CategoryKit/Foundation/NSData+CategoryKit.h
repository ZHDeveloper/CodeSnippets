//
//  NSData+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (CategoryKit)

@property (nonatomic, readonly) NSString *md5String;

@property (nonatomic, readonly) NSString *utf8String;

// 场景：将图片进行base64编码
@property (nonatomic, readonly) NSString *base64EncodedString;

@end
