//
//  TridentConfig.h
//  CK OSX/iOS Framework
//
//  Created by ChuckWang on 12-12-01.
//  Copyright (c) 2012年 ChuckWang. All rights reserved.
//

#import "CKARCMacro.h"

/************************************************************************************************
 *	Define Macros
 ************************************************************************************************/
//===============system macro===============

#ifndef __OPTIMIZE__
//#define NSLog(...) NSLog(__VA_ARGS__)
#define CKLog(fmt, ...)	NSLog((@"%@ [Line: %d] %s " fmt),[[NSString stringWithUTF8String:__FILE__]lastPathComponent], __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__)
#else
#define NSLog(...)
#endif


//===============utility macro===============
/* Color helpers */
#define UIColorFromRGB(r,g,b)		[UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define UIColorFromRGBA(r,g,b,a)	[UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
// e.g. UIColorFromRGBHex(0xCECECE);
#define UIColorFromRGBHex(rgbValue)     [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
// e.g. UIColorFromRGBAHex(0xCECECE, 0.8);
#define UIColorFromRGBAHex(rgbValue,a) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]


#pragma mark - Trident Global Configure
/*************************************************************************************************
 *	Trident Global Configure
 *************************************************************************************************/

