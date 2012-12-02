//
//  NSString+CKMD5.h
//  CKCategory
//
//  Created by Chuck Wang on 12-12-2.
//  Copyright (c) 2012年 Chuck Wang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (CKMD5)

// MD5 hash of the file on the filesystem specified by path
+ (NSString *) stringWithMD5OfFile: (NSString *) path;
// The string's MD5 hash
+ (NSString *) MD5Hash: (NSString *)raw;

@end
