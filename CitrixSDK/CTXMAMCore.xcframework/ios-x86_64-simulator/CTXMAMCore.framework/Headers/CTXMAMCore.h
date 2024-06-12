//
//  CTXMAMCore.h
//  CTXMAMCore
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2018 - 2021 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for CTXMAMCore.
FOUNDATION_EXPORT double CTXMAMCoreVersionNumber;

//! Project version string for CTXMAMCore.
FOUNDATION_EXPORT const unsigned char CTXMAMCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CTXMAMCore/PublicHeader.h>

/*!
 @header CTXMAMCore.h
 Used as the main header for the CTXMAMCore.xcframework.
 Including this header into your source files will add all required headers in order to implement the CTXMAMCore framework properly into your project.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

#import <CTXMAMCore/CTXMAMConfigManager.h>
#import <CTXMAMCore/CTXMAMLogger.h>
#import <CTXMAMCore/CTXMAMNotificationCenter.h>

/*!
 @brief Protocol to be implemented when you want your app to receive callbacks from the CTXMAMCore SDK.
 */
@protocol CTXMAMCoreSdkDelegate <NSObject>

@optional
/*!
@brief This delegate method is used to let the app know that the user has configured a
proxy server to redirect the network requests. This is not allowed and so the app will
shut down.
The app developer needs to let the user know that they need to remove the proxy server
setting and quit the app. The app needs to be exited upon receiving this
delegate callback.
@deprecated This method is deprecated. Use new delegate callback for proxy detection "proxyServerSettingDetectedWithDefaultHandlerOption" instead.
 */
- (void) proxyServerSettingDetected __attribute__((deprecated("Use proxyServerSettingDetectedWithDefaultHandlerOption instead.")));

/*!
@brief This delegate method is used to let the app know that the user has configured a
proxy server to redirect the network requests. This is not allowed and so the app will
shut down.

The app developer needs to let the user know that they need to remove the proxy server
setting and quit the app. The app needs to be exited upon receiving this
delegate callback.
 
@return YES/true if app handles this; otherwise NO/false.
*/

- (BOOL) proxyServerSettingDetectedWithDefaultHandlerOption;

/*!
@brief This delegate method is used to let the app know when the linked SDKs have
 initialized and are ready for interaction with the application.
 For example, you should wait for this event prior to trying to tunnel network traffic  thru the VPN
 when using the CTXMAMNetworkSDK.
 @param online Yes if the user is currently online and able to fetch data from the CEM server. Otherwise NO.
*/
- (void) sdksInitializedAndReady:(BOOL)online __attribute__((deprecated("This method is deprecated and will be removed in a future release. Instead, use the completion block result of initializeSDKsWithCompletionBlock to determine initialization status.")));

@end

@interface CTXMAMCore : NSObject

/*!
 @brief Initiliazes all of the SDKs which are linked to your application so if you have linked against CTXMAMCore and CTXMAMNetwork this call will initialize both SDKs.
 */
+ (void)initializeSDKs __attribute__((deprecated("Use initializeSDKsWithCompletionBlock function instead.")));

/*!
 @brief Initializes all SDKs which have been linked to your application. For example if you have linked against CTXMAMCore and CTXMAMNetwork this call will initialize both SDKs.
 @param initResultHandler a block which is called once the initialization is complete. Check the nilOrError parameter of the block. If nil, the initialization has finished successfully. Otherwise, the error (domain=CTXMAMAppCoreSDKErrorDomain, status code=<CTXMAMAppCoreErrorCode enum>) will give details on why the initialization has failed.
 */
+ (void)initializeSDKsWithCompletionBlock:(nonnull void (^)(NSError * _Nullable nilOrError))initResultHandler;

/*!
 @brief Register the delegate to receive CTXMAMCore SDK callbacks.
 */
+(void)setDelegate:(nonnull id<CTXMAMCoreSdkDelegate>)delegate;

/*!
@brief This API is used to log off third-party applications only when the device is enrolled with Citrix Workspace App. If the device is Secure Hub enrolled, there's no need to call this API and it will always return NO if it is called.
@return Returns YES if the app is logged off successfully, otherwise it will return NO if the app failed to log off.
*/
+ (BOOL)logoffApp;

/*!
 @brief Set Cordova framework relevant info after SDKs are initialized.
 */
+ (void)setCordovaInfoAfterBeingInitialized;
@end

