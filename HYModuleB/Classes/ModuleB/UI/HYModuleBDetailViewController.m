//
//  LJModuleADetailViewController.m
//  LJComponentManager
//
//  Created by phoenix on 16/7/5.
//  Copyright © 2016年 SEU. All rights reserved.
//

#import "HYModuleBDetailViewController.h"
#import "HYModuleBXXXItem.h"

//内部引用定义
#import "HYModuleBKit.h"
/**
 * 用于满足配置到TabController的URL-Controller的直接share跳转
 * 任何URL-Controller均可以配置到TabController中
 * 业务端routeURL跳转时，如果URL对应的controller在tabController中，直接跳转到对应Tab
 * tip: 注意配置到tabController中的Controller所属Class不能重复
 */
static NSMutableDictionary *rootTabClassesDic = nil;

NSString * const kCellIdentifier = @"kCellIdentifier";

@interface HYModuleBDetailViewController ()<UITableViewDelegate, UITableViewDataSource>


@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) NSArray *dataSource;

@property (nonatomic, strong) UIButton *returnButton;

@end

@implementation HYModuleBDetailViewController

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    
    if (self) {
        
        self.title = @"ModuleADetail";
    }
    return self;
}

- (void)viewDidLoad {
    
    [super viewDidLoad];
    [self.view addSubview:self.tableView];

}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    CGRect rect = self.view.bounds;
    self.tableView.frame = CGRectMake(0, 0, rect.size.width, rect.size.height);
}

#pragma mark - event response

- (void)didTappedReturnButton:(UIButton *)button {
    
    if (self.navigationController == nil) {
        
        [self dismissViewControllerAnimated:YES completion:nil];
    } else {
        
        if (self.parentViewController) {
            
            [self.parentViewController dismissViewControllerAnimated:YES completion:nil];
        } else {
            
            [self.navigationController popViewControllerAnimated:YES];
        }
    }
}

#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataSource.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kCellIdentifier];
    cell.textLabel.text = self.dataSource[indexPath.row];
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    //LDBusMediator Call
    if (indexPath.row == 0) {
        
        //presentViewController
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"] withParameters:@{kLJRouteModeKey: @(ELJNavigationModePresent)}];
    }
    
    if (indexPath.row == 1) {
        
        [[HYNavigator getInstance] setHookRouteBlock:nil];
        //[LJComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"]];
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"] withParameters:@{@"key": @"王小虎你好"}];
    }
    
    if (indexPath.row == 2) {
        
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"] withParameters:@{@"image": [UIImage imageNamed:@"image"]}];
    }
    
    if (indexPath.row == 3) {
        
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"] withParameters:@{@"image": @""}];
    }
    
    if (indexPath.row == 4) {
        
        
        [[HYComponentManager serviceForProtocol:@protocol(HYModuleServicePrt)] showAlertWithMessage:@"王小虎最帅" cancelAction:nil confirmAction:^(NSDictionary *info) {
            
            NSLog(@"%@", info);
        }];
    }
    
    if(indexPath.row == 5) {
        
        id<HYModuleItemPrt> item = [[HYComponentManager serviceForProtocol:@protocol(HYModuleServicePrt)] getItemWithName:@"王小虎" age:33];
        
        [[HYComponentManager serviceForProtocol:@protocol(HYModuleServicePrt)] showAlertWithMessage:[item description] cancelAction:nil confirmAction:nil];
    }
    
    if (indexPath.row == 6) {
        
        HYModuleBXXXItem *item = [[HYModuleBXXXItem alloc] init];
        item.itemName = @"王小虎";
        item.itemAge = 33;
        //私有库协议之间调用存在问题
        [[HYComponentManager serviceForProtocol:@protocol(HYModuleServicePrt)] deliveAprotocolModel:item];
    }
    
    if (indexPath.row == 7) {
        
        // 测试notURLController
        UIViewController *controller = [HYComponentManager viewControllerForURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"] withParameters:@{@"image": @""}];
        
        if (controller) {
            
            [self.navigationController pushViewController:controller animated:YES];
        }
    }
    
    // 测试hookURLRouteBlock
    if (indexPath.row == 8) {
        
        [self setURLHookRouteBlock];
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail"]];
    }
    
    // 测试无法找到url的tip提示
    if (indexPath.row == 9) {
        
        [HYComponentManager routeURL:[NSURL URLWithString:@"hycScheme://ModuleADetail1111"]];
    }
}

#pragma mark - getters and setters

- (UITableView *)tableView
{
    if (_tableView == nil) {
        
        _tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        
        [_tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:kCellIdentifier];
    }
    return _tableView;
}

- (NSArray *)dataSource
{
    if (_dataSource == nil) {
        
        _dataSource = @[@"present detail view controller", @"push detail view controller", @"present image", @"present image when error", @"service: show alert", @"service:get protcol model", @"service: set protocol model", @"get url controller", @"route url with hook", @"route url not found"];
    }
    return _dataSource;
}

#pragma mark - test hook route URL

- (void)setURLHookRouteBlock {
    
    [[HYNavigator getInstance] setHookRouteBlock:^BOOL(UIViewController * _Nonnull controller, UIViewController * _Nullable baseViewController, ELJNavigationMode routeMode) {
        
        UIViewController *tabController = [self isViewControllerInTabContainer:controller];
        if (tabController) {
            
            [[HYNavigator getInstance] showURLController:tabController baseViewController:baseViewController routeMode:ELJNavigationModeShare];
            return YES;
        } else {
            
            return NO;
        }
    }];
}

- (UIViewController *)isViewControllerInTabContainer:(UIViewController *)controller {
    if (rootTabClassesDic == nil) {
        
        rootTabClassesDic = [[NSMutableDictionary alloc] initWithCapacity:2];
        UIViewController *rootViewContoller = [UIApplication sharedApplication].delegate.window.rootViewController;
        if (rootViewContoller && [rootViewContoller isKindOfClass:[UITabBarController class]]) {
            
            NSArray *tabControllers = ((UITabBarController *)rootViewContoller).viewControllers;
            [tabControllers enumerateObjectsUsingBlock:^(UIViewController *_Nonnull viewController, NSUInteger idx, BOOL * _Nonnull stop) {
                
                if ([viewController isKindOfClass:[UINavigationController class]]) {
                    
                    viewController = [((UINavigationController *)viewController).viewControllers objectAtIndex:0];
                }
                
                [rootTabClassesDic setObject:viewController forKey:NSStringFromClass([viewController class])];
            }];
        }
    }
    
    if (rootTabClassesDic && rootTabClassesDic.count > 0) {
        
        NSString *controllerKey = NSStringFromClass([controller class]);
        if (controllerKey) {
            
            return [rootTabClassesDic objectForKey:controllerKey];
        } else {
            
            return nil;
        }
    } else {
        
        return nil;
    }
}

@end
