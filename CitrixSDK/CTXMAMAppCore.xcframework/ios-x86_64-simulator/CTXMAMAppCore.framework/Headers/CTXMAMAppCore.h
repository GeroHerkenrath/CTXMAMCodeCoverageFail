//
//  CTXMAMAppCore.h
//  CTXMAMAppCore
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2020-2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CTXMAMAppCore/CTXMAMUserAttributes.h>

//! Project version number for CTXMAMAppCore.
FOUNDATION_EXPORT double CTXMAMAppCoreVersionNumber;

//! Project version string for CTXMAMAppCore.
FOUNDATION_EXPORT const unsigned char CTXMAMAppCoreVersionString[];

// MAM AppCore operation error domain used for NSError objects.
extern NSString * _Nonnull const CTXMAMAppCoreSDKErrorDomain;

typedef NS_ENUM(NSUInteger, CTXMAMAppCoreErrorCode)
{
    CTXMAMAppCoreError_AppNotMAMEntitled            = 1101,     // The application seems to be not published for the user to be managed. Please contact your organization administrator to add this app for the user.
    CTXMAMAppCoreError_AppNotMAMManagedYet          = 1102,     // The application couldn't be MAM managed as it failed to receive MAM policies. To retry fetching the policies, either perform logon again or restart the app.
    CTXMAMAppCoreError_AppNotMAMManagedYet_NetworkConnectionFailure = 11020,     // The application couldn't perform server requests due to network connection failure. Please check device network connectivity and restart the app.
    CTXMAMAppCoreError_LogonNetworkFailure          = 1103,     // Logon failed because of a network connectivity issue with the configured Citrix Endpoint Management (CEM) server. After fixing this issue in SecureHub, perform logon again or restart the app.
};


@interface CTXMAMAppCore : NSObject

/*!
 *  @brief This API performs a logon in Secure Hub.   Can be called to ensure that the user is logged on and prompt for a logon if not.
 *  @param completionBlock Completion block with the status of the logon request.  Argument success is set to YES if already logged on or logging on was successful.
 */
+(void) performLogon:(void(^ _Nullable)(BOOL success))completionBlock;


@end
