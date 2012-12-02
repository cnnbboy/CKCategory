//
//  NSString+CKBase64.m
//  CKCategory
//
//  Created by wangchen on 12-12-1.
//  Copyright (c) 2012年 小西科技. All rights reserved.
//

#import "NSString+CKBase64.h"
#import "GTMBase64.h"
#import "CKARCMacro.h"

@implementation NSString (CKBase64)

+ (NSString *)base64Encoding:(NSString *)rawString
{
    NSData *rawData = [rawString dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
    NSString *encodedString = [[NSString alloc] initWithData:[GTMBase64 encodeData:rawData] encoding:NSUTF8StringEncoding];
    CKAutorelease(encodedString);
    return encodedString;
}

+ (NSString *)base64Decoding:(NSString *)encodedString
{
    NSData *encodedData = [encodedString dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];
    NSString *decodedString = [[NSString alloc] initWithData:[GTMBase64 decodeData:encodedData] encoding:NSUTF8StringEncoding];
    CKAutorelease(decodedString);
    return decodedString;
}

@end
