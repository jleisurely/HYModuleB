#
# Be sure to run `pod lib lint HYModuleB.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'HYModuleB'
  s.version          = '0.2.1'
  s.summary          = '工程示例B'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: 工程示例B,需要时可进行引用，在组件化进入正轨后，删除工程
                       DESC

  s.homepage         = 'http://git.houyicloud.com/ios'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wangyu1001@live.cn' => 'wangyu@houyicloud.com' }
  s.source           = { :git => 'http://git.houyicloud.com/ios/hymoduleb.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  
  s.source_files = 'HYModuleB/Classes/**/*'
  
  # s.resource_bundles = {
  #   'HYModuleB' => ['HYModuleB/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'HYComponentManager'
  s.dependency 'HYModulePrt'
  s.dependency 'HYModuleA'
end
