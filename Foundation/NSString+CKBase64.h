//
//  NSString+CKBase64.h
//  CKCategory
//
//  Created by ChuckWang on 12-12-1.
//  Copyright (c) 2012年 小西科技. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (CKBase64)

+ (NSString *)base64Encoding: (NSString *)rawString;
+ (NSString *)base64Decoding: (NSString *)encodedString;
@end
