//
//  UIImage+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (CategoryKit)

+ (UIImage *)imageWithColor:(UIColor *)color;

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

- (UIImage *)imageByResizeToSize:(CGSize)size;

- (UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

- (UIImage *)imageByCropToRect:(CGRect)rect;

- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius;

- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius corners:(UIRectCorner)corners borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor borderLineJoin:(CGLineJoin)borderLineJoin;

- (UIImage *)imageByRotateLeft90;

- (UIImage *)imageByRotateRight90;

- (UIImage *)imageByRotate180;

- (UIImage *)imageByFlipVertical;

- (UIImage *)imageByFlipHorizontal;

- (UIImage *)imageByGrayscale;

- (UIImage *)imageByBlurSoft;

- (UIImage *)imageByBlurLight;

- (UIImage *)imageByBlurExtraLight;

- (UIImage *)imageByBlurDark;

- (UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

+ (UIImage *)imageByCompress:(UIImage *)oriImage withHeightLimit:(CGFloat)limitHeight andWidthLimit:(CGFloat)limitWidth;

@end
