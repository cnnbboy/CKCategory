//
//  CKARCMacro.h
//  CK OSX/iOS Framework
//
//  Created by Chuck Wang on 12-12-01.
//  Copyright (c) 2012年 ChuckWang. All rights reserved.
//

#import <TargetConditionals.h>

#if ! __has_feature(objc_arc)

	#define CKAutorelease(__v) ([__v autorelease])
	#define CKReturnAutorelease CKAutorelease

	#define CKRetain(__v) ([__v retain])
	#define CKReturnRetain CKRetain

	#define CKRelease(__v) ([__v release], __v = nil)
	#define CKSafeRelease(__v) ([__v release], __v = nil)
	#define CKSuperDealoc [super dealloc];

	#define CKCFRelease(__v) {if(__v)CFRelease(__v);__v = nil;}

	#define CKWeak __unsafe_unretained
    
    #define CKBridge 
    #define CKBridge_Retained 
    #define CKBridge_Transfer 
    
#else
// -fobjc-arc
	#define CKAutorelease(__v) (__v)
	#define CKReturnAutorelease(__v) (__v)

	#define CKRetain(__v) (__v)
	#define CKReturnRetain(__v) (__v)

	#define CKRelease(__v)
	#define CKSafeRelease(__v) (__v = nil)
	#define CKSuperDealoc

	#define CKCFRelease(__v) {if(__v)CFRelease(__v);__v = nil;}

	#define CKWeak weak

    #define CKBridge __bridge
    #define CKBridge_Retained __bridge_retained
    #define CKBridge_Transfer __bridge_transfer

#endif

#define	CKNoneARCDispatchRetain(__v) {if(__v) dispatch_retain(__v);}
#define	CKNoneARCDispatchRelease(__v) {if(__v) dispatch_release(__v), __v = NULL;}

#if ! __has_feature(objc_arc)

	#define CKDispatchRetain CKNoneARCDispatchRetain
	#define CKDispatchRelease CKNoneARCDispatchRelease

#else
	/**
	 * Does ARC support support
	 * It does if the minimum deployment target is iOS 6+ or Mac OS X 8+
	 **/
	#if TARGET_OS_IPHONE

		// Compiling for iOS
		#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 60000 // iOS 6.0 or later
			#define CKDispatchRetain(__v)
			#define CKDispatchRelease(__v) {__v = NULL;}
		#else                                         // iOS 5.X or earlier
			#define CKDispatchRetain CKNoneARCDispatchRetain
			#define CKDispatchRelease CKNoneARCDispatchRelease
		#endif

	#else

		// Compiling for Mac OS X
		#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1080     // Mac OS X 10.8 or later
			#define CKDispatchRetain(__v)
			#define CKDispatchRelease(__v) {__v = NULL;}
		#else
			#define CKDispatchRetain CKNoneARCDispatchRetain
			#define CKDispatchRelease CKNoneARCDispatchRelease
		#endif

	#endif
#endif
