//
//  CTXMAMContainment.h
//  CTXMAMContainment
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2019-2021 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMContainment_h
#define CTXMAMContainment_h

#import <Foundation/Foundation.h>
#import <CTXMAMCore/CTXMAMCore.h>

//! Project version number for CTXMAMContainment.
FOUNDATION_EXPORT double CTXMAMContainmentVersionNumber;

//! Project version string for CTXMAMContainment.
FOUNDATION_EXPORT const unsigned char CTXMAMContainmentVersionString[];

/*!
 @header CTXMAMContainment.h
 Used as the main header for the CTXMAMContainment.framework.
 Including this header into your source files will add all required headers in order to implement the CTXMAMContainment framework properly into your project.
 @copyright Citrix Systems, Inc.
 @updated 2019-10-02
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

/*!
@brief Defines a base value from which all notification codes from the CTXMAMContainment SDK will be offset.
*/
static const NSInteger CTXMAMNotificationCode_Base_CTXMAMContainment = 3000;

/*!
@typedef CTXMAMContainmentNotificationCodes
@brief CTXMAMContainment SDK related notification codes.
*/
typedef enum {
    CTXAlertAppContainment_None = (int)(CTXMAMNotificationCode_Base_CTXMAMContainment),
    CTXAlertAppContainment_DISABLECOPY,
    CTXAlertAppContainment_DISABLEPASTE,
    CTXAlertAppContainment_DISABLEOPENIN,
    CTXAlertAppContainment_DISABLEICLOUD_FM,
    CTXAlertAppContainment_DISABLEICLOUD_KC,
    CTXAlertAppContainment_DISABLEPRINTING,
    CTXAlertAppContainment_DISABLECAMERA,
    CTXAlertAppContainment_DISABLEPHOTOLIBRARY,
    CTXAlertAppContainment_DISABLESMS,
    CTXAlertAppContainment_DISABLELOCATION,
    CTXAlertAppContainment_DISABLEMIC,
    CTXAlertAppContainment_DISABLE_SOCIAL_MEDIA,
    CTXAlertAppContainment_INBOUNDDOCEX,
    CTXAlertAppContainment_GEOFENCE_LocationServicesRequired,
    CTXAlertAppContainment_GEOFENCE_OutsideOfAcceptedArea,
    CTXAlertAppContainment_SECUREMAIL_NotInstalled,
    CTXAlertAppContainment_SECUREMAIL_Upgrade,
    CTXAlertAppContainment_MAILBLOCKED,
    CTXAlertAppContainment_Unknown
} CTXMAMContainmentNotificationCodes;

/*!
@brief Defines a source identifier, which encompasses all notifications originating from the CTXMAMContainment SDK.
*/
extern CTXMAMNotificationSource const CTXMAMNotificationSource_Containment;

/*!
 @brief A protocol to be implemented to enable an app to receive callbacks from the CTXMAMContainment SDK.
 */
@protocol CTXMAMContainmentSdkDelegate <NSObject>

@optional

/*!
 *  @brief Method called when app geolocation is out of the bounds defined by the admin.
 *  @discussion If the method is not implemented, the app is blocked, and an alert is shown stating that the app needs to be closed until the device meets the geofencing criteria. Otherwise, the method implemented by the app will be called when the current location of the device doesn't meet the boundary requirements.
 *  @deprecated This method is deprecated so use "- (BOOL) appIsOutsideGeofencingBoundaryWithDefaultHandlerOption" instead. If this is used with the newer method, then the newer method will get called.
*/
- (void) appIsOutsideGeofencingBoundary __attribute__((deprecated("Use appIsOutsideGeofencingBoundaryWithDefaultHandlerOption instead")));

/*!
 *  @brief Method called when app geolocation is out of the bounds defined by the admin.
 *  @discussion If the method is not implemented or returns NO, the app is blocked, and an alert is shown stating that the app needs to be closed until the device meets the geofencing criteria. Otherwise, the method implemented by the app will be called when the current location of the device doesn't meet the boundary requirements provided that the method returns YES.
 *  This method is newer version of  "- (void) appIsOutsideGeofencingBoundary". So remove older version if implementing this.
 *  @return YES/true if app handles this; otherwise NO/false.
*/
- (BOOL) appIsOutsideGeofencingBoundaryWithDefaultHandlerOption;

/*!
 *  @brief Method called when location services are disabled.
 *  @discussion If the method is not implemented, the app is blocked, and an alert is shown stating that the app needs to be closed until location services are enabled. Otherwise, the method implemented by the app will be called when location services are disabled.
 *  @deprecated This method is deprecated so use "- (BOOL) appNeedsLocationServicesEnabledWithDefaultHandlerOption" instead. If this is used with the newer method, then the newer method will get called.
*/
- (void) appNeedsLocationServicesEnabled __attribute__((deprecated("Use appNeedsLocationServicesEnabledWithDefaultHandlerOption instead")));

/*!
 *  @brief Method called when location services are disabled.
 *  @discussion If the method is not implemented or rerturns NO, the app is blocked, and an alert is shown stating that the app needs to be closed until location services are enabled. Otherwise, the method implemented by the app will be called when location services are disabled provided that the method returns YES.
 *  This method is newer version of  "- (void) appNeedsLocationServicesEnabled". So remove older version if implementing this.
 *  @return YES/true if app handles this; otherwise NO/false.
*/
- (BOOL) appNeedsLocationServicesEnabledWithDefaultHandlerOption;

@end

@interface CTXMAMContainment : NSObject

/*!
 @brief Register a delegate to receive CTXMAMContainment SDK callbacks.
 */
+(void)setDelegate:(id<CTXMAMContainmentSdkDelegate>)delegate;

@end

#endif /* CTXMAMContainment_h */
