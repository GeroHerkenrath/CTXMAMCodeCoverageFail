//
//  CTXMAMLocalAuth.h
//  CTXMAMLocalAuth
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2019-2021 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMLocalAuth_h
#define CTXMAMLocalAuth_h

#import <UIKit/UIKit.h>
//#import "UIApplication+MdxApplication.h"

//! Project version number for CTXMAMLocalAuth.
FOUNDATION_EXPORT double CTXMAMLocalAuthVersionNumber;

//! Project version string for CTXMAMLocalAuth.
FOUNDATION_EXPORT const unsigned char CTXMAMLocalAuthVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CTXMAMLocalAuth/PublicHeader.h>

/*!
 @header CTXMAMLocalAuth.h
 Used as the init header for the CTXMAMLocalAuth.framework.
 Including this header into your source files will add all required headers in order to implement the CTXMAMLocalAuth framework properly into your project.
 @copyright Citrix Systems, Inc.
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

/*!
 @brief Protocol to be implemented when you want your app to receive call backs from LocalAuth SDK.
 */
@protocol CTXMAMLocalAuthSdkDelegate <NSObject>

@optional

/*!
@brief This delegate method is used to let the app know that the device passcode is
necessary since the App Passcode policy is enabled and without the device
passcode this policy cannot function as expected. The user may also enable the
TouchID/FaceID which also means that device passcode is present. When
TouchID/FaceID is enabled, then it will be used first and if its locked out then
device passcode prompt will be presented.

The app developer needs to let the user know that they need to enable
Device Passcode and optionally enable Touch ID/ FaceID.
The app needs to be exited upon receiving this delegate callback.

@return YES/true if the app handles this; otherwise NO/false.
*/
- (BOOL) devicePasscodeRequired;

/*!
@brief
This delegate method is used to let the app know that the Max Offline Period
expiration is approaching. It will be sent 30 minutes, 15 minutes and 5 minutes
before the expiration.

The app developer needs to let the user know that the Max Offline Period is
going to expire soon and this is a warning. Also let the user know that it is
advisable to login soon to continue using the app uninterrrupted.
The app can be continued to be used by the user and no need to quit the app.
@param secondsToExpire The number of seconds remaining to expire the Max Offline Period.
 
@return YES/true if the app handles this; otherwise NO/false.
*/
- (BOOL) maxOfflinePeriodWillExceedWarning:(NSTimeInterval) secondsToExpire;

/*!
@brief
This delegate method is used to let the app know that the Max Offline Period has
expired. To continue using the app the user must go online and login to SecureHub

The app developer needs to let the user know that they need to do a successful
login by going online. Until then the app will not be allowed to
be used. The user may be presented with two buttons: First to exit the app and
second to perform a login. The API to perform login will be available in Core SDK.
 
@return YES/true if the app handles this; otherwise NO/false.
*/
- (BOOL) maxOfflinePeriodExceeded;


@end

@interface CTXMAMLocalAuth : NSObject

/*!
 @brief Register the delegate to receive Local Auth SDK callbacks.
 */
+(void)setDelegate:(id<CTXMAMLocalAuthSdkDelegate>)delegate;

/*!
 @brief Returns whether the Inactivity Timer Policy is enabled and the Local Auth SDK is actively enforcing this policy.
 */
+(BOOL)isInactivityTimerActive;

@end


#endif /* CTXMAMLocalAuth_h */
