//
//  CTXMAMNotificationCenter.h
//  CTXMAMCore
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CTXMAMCore/CTXMAMNotification.h>

/*!
 @header CTXMAMNotificationCenter.h
 This file is automatically included in your code once CTXMAMCore.h is imported.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

NS_ASSUME_NONNULL_BEGIN

/*!
 @brief Defines the code block type which needs to be passed to the registration function.
 */
typedef void (^CTXMAMNotificationEventBlock)(CTXMAMNotification * notification);

/*!
 @brief The object responsible for keeping track of notification registrations which made or removed. It is also responsible for forwarding the notifications to the registered party.
 */
@interface CTXMAMNotificationCenter : NSObject

/*!
 Returns the singleton instance of the CTXMAMNotificationCenter class.
 @returns An instance of the CTXMAMNotificationCenter class.
 */
+ (nullable CTXMAMNotificationCenter *)mainNotificationCenter;
/*!
 @brief registerForNotificationsFromSource used to register a particular block to handle notifications.
 @param source The source of the notifications you would like to receive.
 @param callBackBlock The block of code which is to be called when a notification of the specified source is triggered.
 */
- (void) registerForNotificationsFromSource:(CTXMAMNotificationSource) source usingNotificationBlock:(CTXMAMNotificationEventBlock) callBackBlock;
/*!
 @brief deregisterBlock used to deregister a particular block to handle notifications.
 @param eventBlock The block of code which is to be deregistered from notifications.
 @param source The source of the notifications the registered block is currently using. It must be the same source which was used during registration.
 */
- (void) deregisterBlock:(CTXMAMNotificationEventBlock) eventBlock forNotificationsFromSource:(CTXMAMNotificationSource) source;

@end

NS_ASSUME_NONNULL_END
