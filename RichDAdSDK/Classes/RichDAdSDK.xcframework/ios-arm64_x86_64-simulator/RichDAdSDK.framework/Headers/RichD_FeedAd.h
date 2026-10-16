//
//  RichD_FeedAd.h
//  RichDAdSDK
//
//  Created by 刘士林 on 2024/3/27.
//

#import <Foundation/Foundation.h>
@class RichDShakeInfo;

@protocol RichDFeedAdDelegate;
@class RichD_FeedView;
@class RichD_ADModel;
NS_ASSUME_NONNULL_BEGIN

@interface RichD_FeedAd : NSObject
//广告位id
@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
//当前广告的报价
@property(nonatomic, assign, readonly) long bidPrice;
//竞价成功地址
@property (nonatomic , copy ,readonly)NSArray  * winNoticeUrl ;
//竞价失败地址
@property (nonatomic , copy, readonly) NSArray * lnurl;
//广告视图
@property (nonatomic,strong) RichD_FeedView *feedView;
//懒加载的方式移除了feedView的子控件,请在feedAdDidRender后获取
@property (nonatomic,strong) RichD_FeedView *registerView;
//广告创意类型
@property (nonatomic, assign, readonly) RichDAdCreativeType creativeType;

//使用controller present 落地页
@property (nonatomic, weak) UIViewController *presentAdViewController;

@property (nonatomic , copy) NSString * materialId ;
//用于处理自渲染时的数据模型
@property (nonatomic,strong) RichD_ADModel *feedModel;
@property (nonatomic , copy) NSString * rid ;
/// 外部注入的链路请求 ID（ap）；若设置则优先使用，否则自动生成
@property (nonatomic, copy, nullable) NSString *requestId;
/// 外部注入的 ADN 请求 ID（aq）；若设置则优先使用，否则自动生成
@property (nonatomic, copy, nullable) NSString *adnrequestId;


/// 初始化信息流广告和配置代理
/// - Parameter delegate: 代理
/// - Parameter slotID: 广告位
/// - Parameter isHidden:设置点击关闭时弹出视图是否隐藏，是为隐藏
- (instancetype)loadFeedAdTemplateAdWithSlotID:(NSString *)slotID popupViewHidden:(BOOL)isHidden delegate:(id<RichDFeedAdDelegate>)delegate ;
//竞价成功的上报
- (void)biddingFeedSuccess:(long)price;
//竞价失败的上报
- (void)biddingFeedFailed:(long)price Code:(RichDAdBiddingCode)code;
/// 广告加载成功后调用，根据 shakeCallback 配置返回摇一摇信息；0-关闭时返回 nil
- (nullable RichDShakeInfo *)getShakeInfo;

@end

@protocol RichDFeedAdDelegate <NSObject>
/// 加载成功
- (void)feedAdDidLoad :(RichD_FeedAd*)feedAd;
/// 加载失败
- (void)feedAdDidFailToLoadWithError:(NSError *)error;
/// 渲染成功
- (void)feedAdDidRender:(RichD_FeedAd*)feedAd;
/// 渲染失败
- (void)feedAdDidFailToRenderWithError:(NSError *)error;
/// 广告已经打开
- (void)feedAdDidShow:(RichD_FeedAd *)feedAd;
/// 广告被点击
- (void)feedAdDidClick:(RichD_FeedAd *)feedAd;
/// 广告被关闭
- (void)feedAdDidClose:(RichD_FeedAd *)feedAd;
/// 广告详情页关闭回调
- (void)feedAdDetailViewDidClose:(RichD_FeedAd *)feedAd;
/// 广告详情页将展示回调
- (void)feedAdDetailViewDidPresentScreen:(RichD_FeedAd *)feedAd;
@end

NS_ASSUME_NONNULL_END
