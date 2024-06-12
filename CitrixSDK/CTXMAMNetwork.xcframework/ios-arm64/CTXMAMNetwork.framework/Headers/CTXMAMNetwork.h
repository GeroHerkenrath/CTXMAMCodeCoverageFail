//
//  CTXMAMNetwork.h
//  CTXMAMNetwork
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2018-2021 Citrix Systems, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <os/availability.h>
#import <CTXMAMCore/CTXMAMCore.h>

//! Project version number for SmartNetwork.
FOUNDATION_EXPORT double CTXMAMNetworkVersionNumber;

//! Project version string for SmartNetwork.
FOUNDATION_EXPORT const unsigned char CTXMAMNetworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SmartNetwork/PublicHeader.h>
/*!
 @header CTXMAMNetwork.h
 Used as the main header for the CTXMAMNetwork.framework.
 Including this header into your source files will add all required headers in order to implement the CTXMAMNetwork framework properly into your project.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */


typedef enum vpnErrorReturnType {
    
    vpnNoError = 0,
    vpnClientCertificateExpired,
    vpnClientCertificateRenewalRequired,
    vpnDerivedCredentialsCertificateExpired,
    vpnFullVPNNotSupported,
    vpnLogonRequiredForNetworkAccess,
    vpnUnableToGetProxyConfiguration
    
} vpnErrorReturnType;

extern CTXMAMNotificationSource const CTXMAMNotificationSource_Network;

/*!
 @brief Notification indicate that tunneler is renewed
 */
extern NSString * const CTXMAMNotification_Network_Tunneler_Renewed;

/*!
 @brief Protocol to be implemented when you want your app to receive call backs for different mVPN error scenarios.
 */
@protocol CitrixVPNAlertDelegate <NSObject>

@required
- (void) mVPNError:(NSError *)error;
@end

@interface CTXMAMNetwork : NSObject

/*!
 @brief Register the delegate to receive mVPN related callbacks.
 */
+(void)registerDelegate:(id<CitrixVPNAlertDelegate>)delegate __attribute__((deprecated("Use CTXMAMNotificationCenter registerForNotificationsFromSource:usingNotificationBlock: instead.")));

/*!
 @brief Unsubscribe the delegate.
 */
+(void)deregisterDelegate:(id<CitrixVPNAlertDelegate>)delegate __attribute__((deprecated("Use deregisterBlock: forNotificationsFromSource: instead.")));

@end
