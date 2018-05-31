//
//  NSObject+CategoryKit_KVO.h
//  CategoryKit
//
//  Created by ZhiHua Shen on 2018/5/31.
//  Copyright © 2018年 ZhiHua Shen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (CategoryKit_KVO)

- (void)addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(id obj, id oldVal, id newVal))block;

- (void)removeObserverBlocksForKeyPath:(NSString*)keyPath;

- (void)removeObserverBlocks;

@end
