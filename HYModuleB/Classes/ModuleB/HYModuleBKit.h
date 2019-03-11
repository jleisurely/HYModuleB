//
//  HYModuleBKit.h
//  Pods
//
//  Created by 王玉 on 2019/1/22.
//

#ifndef HYModuleBKit_h
#define HYModuleBKit_h

#ifdef __OBJC__


#import <HYComponentManager/HYCMConnectorPrt.h>

#import <HYModulePrt/HYModuleServicePrt.h>
// 每个业务组件的connector依赖ComponentManager
#import <HYComponentManager/HYComponentManager.h>

//:MARK: ===========  设备尺寸，宽高相关  ===========

#define kScreenHeight ([UIScreen mainScreen].bounds.size.height) //设备高
#define kScreenWidth  ([UIScreen mainScreen].bounds.size.width)  //设备宽
#define kScreenBounds ([UIScreen mainScreen].bounds)             //设备 bounds

#define isiPhoneX CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)
#define isiPhoneXSMax           CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size)
#define isiPhoneXR              CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size)


#define isBangs     (isiPhoneX || isiPhoneXSMax || isiPhoneXR)

#define SYS_STATUSBAR_HEIGHT     (isBangs ? 44 : 20) // 标准系统状态栏高度
#define HOTSPOT_STATUSBAR_HEIGHT (isBangs ? 0 : 20) // 热点栏高度
#define NAVIGATIONBAR_HEIGHT     44 // 导航栏（UINavigationController.UINavigationBar）高度
#define TOOLBAR_HEIGHT           44 // 工具栏（UINavigationController.UIToolbar）高度
#define TABBAR_HEIGHT            (isBangs ? 83: 49) // 标签栏（UITabBarController.UITabBar）高度
#define TABBAR_X_DIF_HEIGHT      (isBangs ? 34: 0)
#define NAV_HEIGHT               (SYS_STATUSBAR_HEIGHT + NAVIGATIONBAR_HEIGHT) //navigationBar高度

#define multiple    kScreenHeight/667 //倍数
#define multiple_w  kScreenWidth/375 //倍数


#define NAVIGATIONBAR_HEIGHT     44 // 导航栏（UINavigationController.UINavigationBar）高度
#define TOOLBAR_HEIGHT           44 // 工具栏（UINavigationController.UIToolbar）高度

#define NAV_HEIGHT               (SYS_STATUSBAR_HEIGHT + NAVIGATIONBAR_HEIGHT) //navigationBar高度
#define KSINGLELINE_WIDTH        1.0f / ([UIScreen mainScreen].scale) //1像素线宽的宏。

// 当前状态栏的高度（可能包含热点栏的高度 和 状态栏的高度） APP_STATUSBAR_HEIGHT=SYS_STATUSBAR_HEIGHT+[HOTSPOT_STATUSBAR_HEIGHT]
#define APP_STATUSBAR_HEIGHT (CGRectGetHeight([UIApplication sharedApplication].statusBarFrame))
// 根据APP_STATUSBAR_HEIGHT判断是否存在热点栏
#define IS_HOTSPOT_CONNECTED (APP_STATUSBAR_HEIGHT==(SYS_STATUSBAR_HEIGHT+HOTSPOT_STATUSBAR_HEIGHT)?YES:NO)
// 无热点栏时，标准系统状态栏高度+导航栏高度(无热点时，导航栏整体的高度)
#define NORMAL_STATUS_AND_NAV_BAR_HEIGHT (SYS_STATUSBAR_HEIGHT+NAVIGATIONBAR_HEIGHT)
// 实时系统状态栏高度+导航栏高度，如有热点栏，其高度包含在APP_STATUSBAR_HEIGHT中。(有热点时，导航栏整体的高度)
#define STATUS_AND_NAV_BAR_HEIGHT (APP_STATUSBAR_HEIGHT+NAVIGATIONBAR_HEIGHT)


//:MARK: ===========  系统版本号、设备判断  ===========

//系统版本号
#define iOS7orLater  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define iOS8orLater  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define iOS9orLater  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define iOS10orLater ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define iOS11orLater ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0)

//设备
#define isiPhone4 CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)
#define isiPhone5 CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define isiPhone5S CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define isiPhone6 CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define isiPhone6Plus CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define isiPhone6s CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define isiPhone6sPlus CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define isiPhone7 CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size)
#define isiPhone7Plus CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size)
#define isiPhone8ZoomIN CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)
#define isiPhone8PlusZoomIN  CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size)
#define isiPhoneXZoomIn CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)
#define isiPhoneX CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size)

#define isiPhone [[UIDevice currentDevice].model isEqualToString:@"iPhone"]
#define isiPad [[UIDevice currentDevice].model isEqualToString:@"iPad"]
#define isiPod [[UIDevice currentDevice].model isEqualToString:@"iPod touch"]
#define isiPadPro CGSizeEqualToSize(CGSizeMake(1366, 1024), [[UIScreen mainScreen] currentMode].size)


//:MARK: ===========  颜色、字体相关  ===========

// ==== 随机色
#define random_color [UIColor colorWithRed:arc4random_uniform(255)/255.0 green:arc4random_uniform(255)/255.0 blue:arc4random_uniform(255)/255.0 alpha:1]

// RGB色值
#define RGBAColor(r,g,b,a)  [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]



#define COLOR_KEYBOARD      [HYToolHelper colorWithHexString:@"#DCDCDC"]//DCDCDC（键盘灰）
#define COLOR_DARKBLACK     [HYToolHelper colorWithHexString:@"#000000"]//000000（大标题黑）
#define COLOR_BLUE          [HYToolHelper colorWithHexString:@"#368DE7"]//368DE7（主色）
#define COLOR_PURPLE        [HYToolHelper colorWithHexString:@"#951CFA"]//951CFA（标签）
#define COLOR_GREEN         [HYToolHelper colorWithHexString:@"#28A946"]//28A946（绿）
#define COLOR_RED           [HYToolHelper colorWithHexString:@"#E84342"]//E84342（红）
#define COLOR_YELLOW        [HYToolHelper colorWithHexString:@"#F2AD27"]//F2AD27（按钮）
#define COLOR_ORANGE        [HYToolHelper colorWithHexString:@"#FC6432"]//FC6432（图标）
#define COLOR_DARKGREY      [HYToolHelper colorWithHexString:@"#4A4A4A"]//4A4A4A（小文字灰）
#define COLOR_LINE          [HYToolHelper colorWithHexString:@"#C7C7C7"]//C7C7C7（线灰）
#define COLOR_LIGHTGRAY     [HYToolHelper colorWithHexString:@"#999999"]//999999（时间／简介灰）
#define COLOR_BACK          [HYToolHelper colorWithHexString:@"#f0f0f0"]//F0F0F0（底色灰）
#define COLOR_WHITE         [HYToolHelper colorWithHexString:@"#FFFFFF"]//FFFFFF (白色)
#define COLOR_DESCRIPTION   [HYToolHelper colorWithHexString:@"#cccccc"]//cccccc (描述灰)
#define COLOR_LIGHT_GREEN   [HYToolHelper colorWithHexString:@"#8cc740"]

//:MARK: ===========  其他  ===========

//应用版本号
#define K_VERSION_SHORT  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]




//本地存储
#define HYUserDefault [NSUserDefaults standardUserDefaults]

//加载图片
#define ImageNamed(_pointer) [[UIImage imageNamed:_pointer] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal]

//获取 AppDelegate
#define MainAppDelegate  ((AppDelegate*)([UIApplication sharedApplication].delegate))

//弱引用
#define uWeakSelf typeof(self) __weak weakSelf = self;

//转JOSN
#define JSON_STR(A) [[NSString alloc] initWithData:[NSJSONSerialization dataWithJSONObject:@[A] options:NSJSONWritingPrettyPrinted error:nil] encoding:NSUTF8StringEncoding]

//字符串格式化
#define kString_Format(fmt, ...) [NSString stringWithFormat:fmt, ##__VA_ARGS__]

//日志输出
#ifdef DEBUG
#define E_Log(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__]);
#else
#define E_Log(...);
#endif


#endif


#endif /* HYModuleBKit_h */
