//
//  NSString+CKNetworkAdditions.h
//  CKCategoryTest
//
//  Created by Chuck Wang on 12-12-2.
//  Copyright (c) 2012年 小西科技. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (CKNetworkAdditions)

- (NSString*) urlEncodedString;
- (NSString*) urlDecodedString;

@end
