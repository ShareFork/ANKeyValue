//
//  ANKeyValueTable.h
//  Araneo
//
//  Created by SpringOx on 14/12/12.
//  Copyright (c) 2014年 SpringOx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ANKeyValueData.h"

@interface ANKeyValueTable : NSObject

+ (id)tableWithName:(NSString *)name version:(NSString *)version resumable:(BOOL)resumable;

+ (id)tableForUser:(NSString *)name version:(NSString *)version;

+ (id)userDefaultTable;

#pragma mark -
- (id)initWithData:(ANKeyValueData *)data;

// 支持持久化操作，强制执行，springox(20150618)
- (void)synchronize;

// 支持持久化操作，可选择定时执行还是强制执行，atomically==YES为定时执行，定时执行对于频繁持久化操作更有效，减少重复持久化操作的浪费，springox(20150618)
- (void)synchronize:(BOOL)atomically;

- (BOOL)isArchiving;

- (void)clear;

#pragma mark -
- (void)setInt:(int)value withKey:(id <NSCopying>)key;

- (void)setInteger:(NSInteger)value withKey:(id <NSCopying>)key;

- (void)setFloat:(float)value withKey:(id <NSCopying>)key;

- (void)setDouble:(double)value withKey:(id <NSCopying>)key;

- (void)setBool:(BOOL)value withKey:(id <NSCopying>)key;

- (void)setValue:(id <NSCoding>)value withKey:(id <NSCopying>)key;

- (void)encryptContent:(NSString *)content withKey:(id <NSCopying>)key;

#pragma mark -
- (int)intWithKey:(id <NSCopying>)key;

- (NSInteger)integerWithKey:(id <NSCopying>)key;

- (float)floatWithKey:(id <NSCopying>)key;

- (double)doubleWithKey:(id <NSCopying>)key;

- (id)valueWithKey:(id <NSCopying>)key;

- (id)decryptContentWithKey:(id <NSCopying>)key;

#pragma mark -
- (NSArray *)allKeys;

- (NSArray *)allValues;

- (void)removeValueWithKey:(id <NSCopying>)key;

- (void)removeAllValues;

@end
