//
//  NSString+CategoryKit.m
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import "NSString+CategoryKit.h"
#import "NSData+CategoryKit.h"

@implementation NSString (CategoryKit)

- (NSString *)md5String {
    return [self dataUsingEncoding:NSUTF8StringEncoding].md5String;
}

- (NSString *)base64EncodedString {
    return [[self dataUsingEncoding:NSUTF8StringEncoding] base64EncodedString];
}

+ (NSString *)stringWithBase64EncodedString:(NSString *)base64EncodedString {
    
    NSData *data = [[NSData alloc] initWithBase64EncodedString:base64EncodedString options:0];

    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

- (NSString *)stringByURLEncode {
    return [self stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
}

- (NSString *)stringByURLDecode {
    NSString *decode = [self stringByRemovingPercentEncoding];
    if (decode) {
        return decode;
    }
    else {
        return self;
    }
}

- (CGSize)sizeForFont:(UIFont *)font size:(CGSize)size mode:(NSLineBreakMode)lineBreakMode {
    CGSize result;
    if (!font) font = [UIFont systemFontOfSize:12];
    if ([self respondsToSelector:@selector(boundingRectWithSize:options:attributes:context:)]) {
        NSMutableDictionary *attr = [NSMutableDictionary new];
        attr[NSFontAttributeName] = font;
        if (lineBreakMode != NSLineBreakByWordWrapping) {
            NSMutableParagraphStyle *paragraphStyle = [NSMutableParagraphStyle new];
            paragraphStyle.lineBreakMode = lineBreakMode;
            attr[NSParagraphStyleAttributeName] = paragraphStyle;
        }
        CGRect rect = [self boundingRectWithSize:size
                                         options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading
                                      attributes:attr context:nil];
        result = rect.size;
    } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        result = [self sizeWithFont:font constrainedToSize:size lineBreakMode:lineBreakMode];
#pragma clang diagnostic pop
    }
    return result;
}

- (CGFloat)widthForFont:(UIFont *)font {
    CGSize size = [self sizeForFont:font size:CGSizeMake(HUGE, HUGE) mode:NSLineBreakByWordWrapping];
    return size.width;
}

- (CGFloat)heightForFont:(UIFont *)font width:(CGFloat)width {
    CGSize size = [self sizeForFont:font size:CGSizeMake(width, HUGE) mode:NSLineBreakByWordWrapping];
    return size.height;
}


@end
