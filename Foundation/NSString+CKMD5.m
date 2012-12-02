//
//  NSString+CKMD5.m
//  CKCategory
//
//  Created by Chuck Wang on 12-12-2.
//  Copyright (c) 2012年 Chuck Wang. All rights reserved.
//

#import "NSString+CKMD5.h"
#import <CommonCrypto/CommonDigest.h>
#import "CKARCMacro.h"

@implementation NSString (CKMD5)

+ (NSString *) stringWithMD5OfFile: (NSString *) path {
    
	NSFileHandle *handle = [NSFileHandle fileHandleForReadingAtPath: path];
	if (handle == nil) {
		return nil;
	}
	
	CC_MD5_CTX md5;
	CC_MD5_Init (&md5);
	
	BOOL done = NO;
	
	while (!done) {
        
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
		NSData *fileData = [[NSData alloc] initWithData: [handle readDataOfLength: 4096]];
		CC_MD5_Update (&md5, [fileData bytes], [fileData length]);
		
		if ([fileData length] == 0) {
			done = YES;
		}
		
        CKRelease(fileData);
        CKRelease(pool);		
	}
	
	unsigned char digest[CC_MD5_DIGEST_LENGTH];
	CC_MD5_Final (digest, &md5);
	NSString *s = [NSString stringWithFormat: @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
				   digest[0],  digest[1], 
				   digest[2],  digest[3],
				   digest[4],  digest[5],
				   digest[6],  digest[7],
				   digest[8],  digest[9],
				   digest[10], digest[11],
				   digest[12], digest[13],
				   digest[14], digest[15]];
    
	return s;
	
}

+ (NSString *) MD5Hash: (NSString *)raw
{
	
	CC_MD5_CTX md5;
	CC_MD5_Init (&md5);
	CC_MD5_Update (&md5, [raw UTF8String], [raw length]);
    
	unsigned char digest[CC_MD5_DIGEST_LENGTH];
	CC_MD5_Final (digest, &md5);
	NSString *result = [NSString stringWithFormat: @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
				   digest[0],  digest[1], 
				   digest[2],  digest[3],
				   digest[4],  digest[5],
				   digest[6],  digest[7],
				   digest[8],  digest[9],
				   digest[10], digest[11],
				   digest[12], digest[13],
				   digest[14], digest[15]];
    
	return result;
	
}

@end
