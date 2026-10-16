#
# Be sure to run `pod lib lint RichDAdSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'RichDAdSDK'
  s.version          = '3.9.2.10'
  s.summary          = 'RichD 广告 SDK'

  s.description      = <<-DESC
  RichD 广告 SDK。
  DESC

  s.homepage         = 'https://github.com/dmdsp/RichDAdSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'shilin.liu' => 'shilin.liu@domob.cn' }
  s.source           = { :git => 'https://github.com/dmdsp/RichDAdSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'

  s.frameworks = 'AdSupport', 'AppTrackingTransparency', 'CoreLocation', 'CoreMotion', 'CoreTelephony'
  s.vendored_frameworks = 'RichDAdSDK/Classes/RichDAdSDK.xcframework'

  s.resource_bundles = {
      'RichDAdSDK_Bundle' => ['RichDAdSDK/Classes/RichDAdSDK_Bundle.bundle/**/*']
  }

  s.static_framework = true

end
