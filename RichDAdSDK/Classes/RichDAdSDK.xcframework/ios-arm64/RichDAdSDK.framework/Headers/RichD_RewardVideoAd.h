//
//  RichD_RewardVideoAd.h
//  RichDAdSDK
//
//  Created by 刘士林 on 2024/3/27.
//

#import <Foundation/Foundation.h>
@class RichDShakeInfo;

@protocol RichDRewardVideoAdDelegate;
@class RichD_RewardVideoView;
@class RichD_RewarVideoModel;

NS_ASSUME_NONNULL_BEGIN

@interface RichD_RewardVideoAd : NSObject
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;
//竞价成功地址
@property (nonatomic , copy ,readonly)NSArray  * winNoticeUrl ;
//竞价失败地址
@property (nonatomic , copy, readonly) NSArray * lnurl;
//加载广告时的model
@property (nonatomic , strong, readonly) RichD_RewarVideoModel * videoModel ;
//使用controller present 落地页
@property (nonatomic, weak) UIViewController *presentAdViewController;


@property (nonatomic , copy) NSString * materialId ;
@property (nonatomic , copy) NSString * rid ;
/// 外部注入的链路请求 ID（ap）；若设置则优先使用，否则自动生成
@property (nonatomic, copy, nullable) NSString *requestId;
/// 外部注入的 ADN 请求 ID（aq）；若设置则优先使用，否则自动生成
@property (nonatomic, copy, nullable) NSString *adnrequestId;

/// 初始化激励视频和配置、代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位id
/// - Parameter model:  额外的数据
- (instancetype)loadRewardVideoAdTemplateAdWithSlotID:(NSString *)slotID withRewarVideoModel:(RichD_RewarVideoModel*)model delegate:(id<RichDRewardVideoAdDelegate>)delegate ;
//竞价成功的上报
- (void)biddingRewardVideoSuccess:(long)price;
//竞价失败的上报
- (void)biddingRewardVideoFailed:(long)price Code:(RichDAdBiddingCode)code;
/// 展示广告
/// - Parameter viewController: 传入一个控制器
-(void)showRewardVideoViewInRootViewController:(UIViewController *)viewController;
/// 广告加载成功后调用，根据 shakeCallback 配置返回摇一摇信息；0-关闭时返回 nil
- (nullable RichDShakeInfo *)getShakeInfo;

@end

@protocol RichDRewardVideoAdDelegate <NSObject>
/// 加载成功
- (void)rewardVideoAdDidLoad :(RichD_RewardVideoAd*)rewardVideoAd;
/// 加载失败
- (void)rewardVideoAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)rewardVideoAdDidRender:(RichD_RewardVideoAd*)rewardVideoAd;;
/// 渲染失败
- (void)rewardVideoAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)rewardVideoAdDidShow:(RichD_RewardVideoAd *)rewardVideoAd;
/// 广告被点击
- (void)rewardVideoAdDidClick:(RichD_RewardVideoAd *)rewardVideoAd;
/// 广告被关闭
- (void)rewardVideoAdDidClose:(RichD_RewardVideoAd *)rewardVideoAd;
///播放失败的回调
- (void)rewardVideoAdDidFailToShowWithError:(NSError *)error;
///发奖
- (void)rewardVideoAdDidComplete:(RichD_RewardVideoAd *)rewardVideoAd;
///视频播放完成
- (void)rewardVideoAdPlayToEndTime:(RichD_RewardVideoAd *)rewardVideoAd;
/// 广告详情页关闭回调
- (void)rewardVideoAdDetailViewDidClose:(RichD_RewardVideoAd *)rewardVideoAd;
/// 广告详情页将展示回调
- (void)rewardVideoAdDetailViewDidPresentScreen:(RichD_RewardVideoAd *)rewardVideoAd;
@end

NS_ASSUME_NONNULL_END
