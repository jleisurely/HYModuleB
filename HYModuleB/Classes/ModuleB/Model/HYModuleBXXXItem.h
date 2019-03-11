//
//  LJModuleAXXXItem.h
//  LJComponentManager
//
//  Created by phoenix on 16/7/5.
//  Copyright © 2016年 SEU. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HYModulePrt/HYModuleItemPrt.h>

/**
 *  LJModuleAXXXItem
 *  模块内部的模型对象构造
 */


@interface HYModuleBXXXItem : NSObject<HYModuleItemPrt> {
    
}
@property(nonatomic, readwrite) NSString *__nonnull itemName;
@property(nonatomic, readwrite) int itemAge;

- (nonnull instancetype)initWithItemName:(nonnull NSString *)itemName
                                 itemAge:(int)itemAge;

@end
