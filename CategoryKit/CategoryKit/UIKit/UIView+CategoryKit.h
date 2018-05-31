//
//  UIView+CategoryKit.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (CategoryKit)

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;
@property (nonatomic) CGFloat centerX;
@property (nonatomic) CGFloat centerY;
@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize  size;

@property (nullable, nonatomic, readonly) UIViewController *viewController;

- (UIImage *)snapshotImage;

- (UIImage *)snapshotImageAfterScreenUpdates:(BOOL)afterUpdates;

- (void)setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius;

- (CGPoint)convertPoint:(CGPoint)point toViewOrWindow:(nullable UIView *)view;

- (CGPoint)convertPoint:(CGPoint)point fromViewOrWindow:(nullable UIView *)view;

- (CGRect)convertRect:(CGRect)rect toViewOrWindow:(nullable UIView *)view;

- (CGRect)convertRect:(CGRect)rect fromViewOrWindow:(nullable UIView *)view;

- (void)removeAllSubviews;

@end
