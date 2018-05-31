//
//  NSData+CategoryKit.m
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import "NSData+CategoryKit.h"
#include <CommonCrypto/CommonCrypto.h>

@implementation NSData (CategoryKit)

- (NSString *)md5String {
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(self.bytes, (CC_LONG)self.length, result);
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}

- (NSString *)utf8String {
    if (self.length > 0) {
        return [[NSString alloc] initWithData:self encoding:NSUTF8StringEncoding];
    }
    return @"";
}

- (NSString *)base64EncodedString {
    return [self base64EncodedStringWithOptions:0];
}



@end
