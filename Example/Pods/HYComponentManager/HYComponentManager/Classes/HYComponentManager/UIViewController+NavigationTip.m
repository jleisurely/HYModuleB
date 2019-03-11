//
//  UIViewController+NavigationTip.m
//  LJComponentManager
//
//  Created by phoenix on 16/7/4.
//  Copyright © 2016年 SEU. All rights reserved.
//

#import "UIViewController+NavigationTip.h"
#import "HYCMTipViewController.h"

@implementation UIViewController (NavigationTip)

+(nonnull UIViewController *)lj_paramsError {
    
    return [HYCMTipViewController paramsErrorTipController];
}

+(nonnull UIViewController *)lj_notURLController {
    
    return [HYCMTipViewController notURLTipController];
}

+(nonnull UIViewController *)lj_notFound {
    
    return [HYCMTipViewController notFoundTipConctroller];
}

@end
