#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "HYCMConnectorPrt.h"
#import "HYCMTipViewController.h"
#import "HYComponentManager.h"
#import "HYNavigator.h"
#import "UIViewController+NavigationTip.h"

FOUNDATION_EXPORT double HYComponentManagerVersionNumber;
FOUNDATION_EXPORT const unsigned char HYComponentManagerVersionString[];

