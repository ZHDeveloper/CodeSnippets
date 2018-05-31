//
//  CategoryKitMacro.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/30.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#ifndef CategoryKitMacro_h
#define CategoryKitMacro_h

#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
        #else
        #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
        #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
        #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
        #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif

// .h
#define singleton_interface(class) + (instancetype)shared ## class;
// .m
#define singleton_implementation(class) \
static class *_instance; \
\
+ (id)allocWithZone:(struct _NSZone *)zone \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
\
return _instance; \
} \
\
+ (instancetype)shared ## class \
{ \
    if (_instance == nil) { \
        _instance = [[class alloc] init]; \
    } \
    \
    return _instance; \
}

#define kScreenSize [UIScreen mainScreen].bounds.size

#define kScreenWidth [UIScreen mainScreen].bounds.size.width

#define kScreenHeight [UIScreen mainScreen].bounds.size.height

#define DegreesToRadians(x) (M_PI * (x) / 180.0)
#define RadiansToDegrees(radian) (radian*180.0)/(M_PI)

#define kTempPath NSTemporaryDirectory()

#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

#define KDocumentURL [[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask] lastObject]

#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

#define kCacheURL [[[NSFileManager defaultManager]   URLsForDirectory:NSCachesDirectory inDomains:NSUserDomainMask] lastObject]

#define kLibraryPath [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) firstObject]

#define kLibraryURL [[[NSFileManager defaultManager] URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask] lastObject]

#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

#define HexColor(rgbValue) [UIColor colorWithRed: ((float)((rgbValue & 0xFF0000) >> 16))/255.0 green: ((float)((rgbValue & 0xFF00) >> 8))/255.0 blue: ((float)(rgbValue & 0xFF))/255.0 alpha: 1.0]

#endif /* CategoryKitMacro_h */
