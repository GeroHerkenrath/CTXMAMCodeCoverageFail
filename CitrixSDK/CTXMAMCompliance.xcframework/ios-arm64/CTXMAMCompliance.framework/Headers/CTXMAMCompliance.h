//
//  CTXMAMCompliance.h
//  CTXMAMCompliance
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2019-2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


/*!
 @header CTXMAMCompliance.h
 Used as the main header for the CTXMAMCompliance.framework.
 Including this header into your source files will add all required headers in order to implement the CTXMAMCompliance framework properly into your project.
 @copyright Citrix Systems, Inc.
 @updated 2019-12-02
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */


//! Project version number for CTXMAMCompliance.
FOUNDATION_EXPORT double CTXMAMComplianceVersionNumber;

//! Project version string for CTXMAMCompliance.
FOUNDATION_EXPORT const unsigned char CTXMAMComplianceVersionString[];


NS_ASSUME_NONNULL_BEGIN

/*!
 *  @brief CTXMAM Compliance SDK security actions or compliance violations.
 */
extern NSString * const CTXMAMComplianceErrorDomain;


typedef enum CTXMAMComplianceError {
    CTXMAMCompliance_SecurityAction_AdminAppLock = 1,
    CTXMAMCompliance_SecurityAction_AdminAppWipe,
    CTXMAMCompliance_SecurityAction_ContainerSelfDestruct,
    CTXMAMCompliance_SecurityAction_AppDisabled,
    CTXMAMCompliance_SecurityAction_DateAndTimeChanged,
    CTXMAMCompliance_SecurityAction_UserChanged,
    CTXMAMCompliance_Violation_Jailbroken,
    CTXMAMCompliance_Violation_DevicePasscodeRequired,
    CTXMAMCompliance_Violation_EDP_BlockApp,
    CTXMAMCompliance_Violation_EDP_WarnUser,
    CTXMAMCompliance_Violation_EDP_InformUser,
    CTXMAMComplianceError_Other
} CTXMAMComplianceError;


/*!
 * @brief This protocol provides callback with NSError objects with CTXMAMComplianceError codes and localized message strings.
 * @discussion App should implement any callback methods that it wants to have custom behavior for, and the implementations should adhere to the documented guidelines.
 */
@protocol CTXMAMComplianceDelegate  <NSObject>

/// Security Actions
/*!
 *  @brief To handle App Lock security action imposed by organization admin.
 *  @discussion Handle it by requiring the user to logon (call performLogonWithErrorContext:completionHandler:) in order to continue using the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleAdminLockAppSecurityActionForError:(NSError*)error;

/*!
 *  @brief To handle App Wipe security action imposed by organization admin.
 *  @discussion Handle it by requiring the user to logon (call performLogonWithErrorContext:completionHandler:) in order to continue using the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleAdminWipeAppSecurityActionForError:(NSError*)error;

/*!
 *  @brief To handle app container self-destruct security action imposed by organization admin.
 *  @discussion Handle it by requiring the user to logon (call performLogonWithErrorContext:completionHandler:) in order to continue using the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleContainerSelfDestructSecurityActionForError:(NSError*)error;

/*!
 *  @brief To handle admin imposed App Disable security action.
 *  @discussion Handle it by requiring the user to quit the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleAppDisabledSecurityActionForError:(NSError*)error;

/*!
 *  @brief To handle significant date and time change security action.
 *  @discussion Handle it by requiring the user to logon (call performLogonWithErrorContext:completionHandler:) in order to continue using the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleDateAndTimeChangeSecurityActionForError:(NSError*)error;

/*!
 *  @brief To handle XenMobile user account change security action.
 *  @discussion Handle it by requiring the user to quit the app and suggesting the user to re-install the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleUserChangeSecurityActionForError:(NSError*)error;


/// Compliance Violations
/*!
 *  @brief To handle compliance violation of using a jailbroken device.
 *  @discussion Handle it by requiring the user to quit the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleJailbreakComplianceViolationForError:(NSError*)error;

/*!
 *  @brief To handle compliance violation of not setting the device passcode.
 *  @discussion Handle it by requiring the user to quit the app and asking the user to set the app passcode before re-using the app.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleDevicePasscodeComplianceViolationForError:(NSError*)error;

/*!
 *  @brief To handle compliance violation when the device falls below the minimum compliance requirements of encryption.
 *  @discussion If error code is
 *
 *   - CTXMAMCompliance_Violation_EDP_BlockApp: Handle it by requiring the user to quit the app and suggesting to re-launch the app after fixing the compliance violation based on the suggestion mentioned in the user info message.
 *
 *   - CTXMAMCompliance_Violation_EDP_WarnUser: Handle it by warning user of the compliance violation and risks of leaking app container data when device is lost. For example, by prompting an obtrusive alert view.
 *
 *   - CTXMAMCompliance_Violation_EDP_InformUser: Handle it by unobtrusively informing user of the compliance violation and risks of leaking app container data when device is lost.
 *  @param error CTXMAMComplianceError error code and localized message in NSLocalizedDescriptionKey of user info.
 *  @return YES/true if app handles this; otherwise NO/false.
 */
- (BOOL) handleEDPComplianceViolationForError:(NSError*)error;

@end


@interface CTXMAMCompliance : NSObject

@property (readwrite,atomic,weak) id<CTXMAMComplianceDelegate> delegate;

+ (instancetype)sharedInstance;


/*!
 *  @note API to perform logon when needed to handle any compliance violations or to perform any security action
 *  @param errorContext CTXMAMComplianceError error object received from CTXMAMComplianceDelegate methods.
 *  @param completionBlock Completion block with status of the logon request.
 */
-(void) performLogonWithErrorContext:(NSError*)errorContext completionHandler:(void(^)(BOOL success))completionBlock;


/*!
 *  @note An optional method for app developers to call compliance checks on demand.
 *  @return An array of compliance check errors as NSError objects with error code of type CTXMAMComplianceError.
 */
-(nullable NSArray<NSError *> *) checkCompliance;


@end

NS_ASSUME_NONNULL_END
