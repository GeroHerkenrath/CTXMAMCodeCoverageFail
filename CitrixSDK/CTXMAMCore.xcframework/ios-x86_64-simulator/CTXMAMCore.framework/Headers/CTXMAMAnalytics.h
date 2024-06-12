//
//  CTXMAMAnalytics.h
//
//  Created by Chris Pavlou on 5/2/16.
//  Copyright © 2017-2023 Cloud Software Group, Inc. All Rights Reserved. Confidential & Proprietary.
//

#import <Foundation/Foundation.h>
#import <CTXMAMCore/CTXMAMPolicyDimensions.h>
#import <CTXMAMCore/CTXMAMAnalyticsConfig.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const MdxAnalytics_DisableGAClientProperty;

extern NSString * const MdxAnalytics_PolicyTrackingFile;

// Categories
extern NSString * const MdxAnalyticsCategory_LifeEvent;
extern NSString * const MdxAnalyticsCategory_Alert;
extern NSString * const MdxAnalyticsCategory_Toast;
extern NSString * const MdxAnalyticsCategory_Auth;
extern NSString * const MdxAnalyticsCategory_Flip;
extern NSString * const MdxAnalyticsCategory_Error;
extern NSString * const MdxAnalyticsCategory_LowLevelCalls;
extern NSString * const MdxAnalyticsCategory_NSURL;
extern NSString * const MdxAnalyticsCategory_EDP;
extern NSString * const MdxAnalyticsCategory_UIWebView;
extern NSString * const MdxAnalyticsCategory_WKWebView;

//Action
extern NSString * const MdxAnalyticsAction_StartDecrypt;
extern NSString * const MdxAnalyticsAction_DecryptFailed;
extern NSString * const MdxAnalyticsAction_DecryptCompleted;
extern NSString * const MdxAnalyticsAction_ErrorCode;
extern NSString * const MdxAnalyticsAction_UIWebView_DelegateSet;
extern NSString * const MdxAnalyticsAction_WKWebView_Init;
extern NSString * const MdxAnalyticsAction_WKWebView_ProcessDidTerminate;

// Timing variables
extern NSString * const MdxAnalyticsTiming_LaunchTime;

// Components
extern NSString * const MdxAnalyticsComponent_StoreAccount;
extern NSString * const MdxAnalyticsComponent_AGConfiguration;

@interface CTXMAMAnalytics : NSObject 
@property (readonly) BOOL analyticsEnabled, analyticsInitialized, analyticsConfigured, extendedAnalyticsFeatureOn, anonymousAnalytics;

+(instancetype)sharedInstance;

-(void)appForegroundedFromLaunch:(BOOL)fromLaunch;
-(void)configure;
-(void)didEnterBackground;

#pragma mark MDX sub-component event submission - Direct access methods

/* Controlled by the extended-analytics flag */
-(void)sendEventWithCategory:(NSString *)category
					  action:(NSString *)action
					   label:(nullable NSString *)label				/* optional */
					   value:(nullable NSNumber *)value				/* optional */
;

/* Controlled by the extended-analytics flag */
-(void)sendTimingWithCategory:(NSString *)category
					 interval:(NSNumber *)intervalMillis
						 name:(NSString *)name
						label:(nullable NSString *)label			/* optional */
;

/* Controlled by the extended-analytics flag */
-(void)sendScreenview:(NSString *)screenName;

#pragma mark MDX sub-component event submission - Abstract methods

/* NOT controlled by the extended-analytics flag */
-(void)sendMdxErrorEventWithComponent:(NSString *)component			/* this maps to the action property */
							  message:(NSString *)message			/* this maps to the label property */
								value:(nullable NSNumber *)value 	/* optional */
;

-(void)sendMdxExplicitSDKLowLevelCallsEventWithAction: (NSString *)action;
-(void)sendMdxExplicitSDKNSURLEventWithAction: (NSString *)action;
-(void)sendMdxExplicitSDKEventWithAction: (NSString*) category withAction:(NSString *)action;

-(void)sendMdxEndpointDataProtectionStartEventWithValue: (NSNumber *)value;

-(void)sendMdxEndpointDataProtectionFinishCompletedEventWithValue: (NSNumber *)value withStatus:(NSString*) status;

-(void)sendMdxEndpointDataProtectionFinishFailedEventWithValue: (NSNumber *)value withStatus:(NSString*) status;

-(void)sendMdxEndpointDataProtectionErrorCodeEventWithValue: (NSString *)codeError;

-(void)sendMdxUIWebViewDelegateSet: (NSString *)webViewAddr;

-(void)sendMdxWKWebViewInitEvent;
-(void)sendMdxWKWebViewProcessDidTerminateEvent: (NSString *)url;

-(void)sendHitsInBackground;

-(BOOL)isGoogleAnalytics4Enabled;

@end

NS_ASSUME_NONNULL_END
