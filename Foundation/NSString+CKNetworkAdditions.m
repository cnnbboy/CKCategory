//
//  NSString+CKNetworkAdditions.m
//  CKCategoryTest
//
//  Created by Chuck Wang on 12-12-2.
//  Copyright (c) 2012年 小西科技. All rights reserved.
//

#import "NSString+CKNetworkAdditions.h"
#import "CKARCMacro.h"


@implementation NSString (CKNetworkAdditions)

- (NSString*) urlEncodedString {
    
    CFStringRef encodedCFString = CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault, 
                                                                          (CKBridge CFStringRef) self, 
                                                                          nil,
                                                                          CFSTR("?!@#$^&%*+,:;='\"`<>()[]{}/\\| "), 
                                                                          kCFStringEncodingUTF8);
    
    NSString *encodedString = [[NSString alloc] initWithString:(CKBridge_Transfer NSString*) encodedCFString];    
    
    CKCFRelease(encodedCFString);
    CKAutorelease(encodedString);
    
    if(!encodedString)
        encodedString = @"";    
    
    return encodedString;
}


- (NSString*) urlDecodedString {
    
    CFStringRef decodedCFString = CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault, 
                                                                                          (CKBridge CFStringRef) self, 
                                                                                          CFSTR(""),
                                                                                          kCFStringEncodingUTF8);
    
    // We need to replace "+" with " " because the CF method above doesn't do it
    NSString *decodedString = [[NSString alloc] initWithString:(CKBridge_Transfer NSString*) decodedCFString];    
    CKCFRelease(decodedCFString);
    CKAutorelease(decodedString);
    return (!decodedString) ? @"" : [decodedString stringByReplacingOccurrencesOfString:@"+" withString:@" "];
}
 

@end
