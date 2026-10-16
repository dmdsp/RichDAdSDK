//
//  RichDShakeInfo.h
//  RichDAdSDK
//

#import <Foundation/Foundation.h>
@class DM_AdsConfig;

NS_ASSUME_NONNULL_BEGIN

@interface RichDShakeInfo : NSObject

@property (nonatomic, assign) double angle;
@property (nonatomic, assign) double acceleration;
@property (nonatomic, assign) double time;

+ (nullable RichDShakeInfo *)shakeInfoWithOption:(DM_AdsConfig *)option;

@end

NS_ASSUME_NONNULL_END
