//
//  CTXMAMNotification.h
//  CTXMAMCore
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

#ifndef __CTXMAMNOTIFICATION_H__
#define __CTXMAMNOTIFICATION_H__

#import <Foundation/Foundation.h>

/*!
 @header CTXMAMNotification.h
 This file is automatically included in your code once CTXMAMCore.h is imported.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

NS_ASSUME_NONNULL_BEGIN

typedef NSString * CTXMAMNotificationSource;

/*!
 @brief Defines source of which encompasses all notifications from all of the SDKs
 @deprecated This source is deprecated. Use individual CTXMAMNotificationSources instead. For example: CTXMAMNotificationSource_Core.
 */
extern CTXMAMNotificationSource const CTXMAMNotificationSource_All __attribute__((deprecated("Use individual CTXMAMNotificationSources instead. For example: CTXMAMNotificationSource_Core.")));

/*!
 @brief Defines source of which encompasses all notifications from the CTXMAMCore SDKs.
 */
extern CTXMAMNotificationSource const CTXMAMNotificationSource_Core;

/*!
 @brief The object which is given to subscribers when a notification is sent out to subscribers.
 */
@interface CTXMAMNotification : NSObject

/*!
 @brief A propoerty which hold the source of the notification
 */
@property (nonatomic, readonly, copy) CTXMAMNotificationSource Source;
/*!
 @brief A localized message which explains the reason for the notification.
 */
@property (nonatomic, readonly, copy) NSString * Message;
/*!
 @brief The error message associated with the notification. This item may be nil.
 */
@property (nonatomic, readonly, copy) NSError * Error;

/*!
 @brief notificationWithSource:andMessage constructor creates a new notification object with the specified source and message.
 @param source The source of the notification.
 @param message The message which describes the notification.
 @return An instance of the CTXMAMNotification object with the specified source and message.
 */
+ (instancetype) notificationWithSource:(CTXMAMNotificationSource)source andMessage:(NSString *)message;
/*!
 @brief notificationWithSource:andMessage:andError constructor creates a new notification object with the specified source and message.
 @param source The source of the notification.
 @param message The message which describes the notification.
 @param error The error which is to be associates with the notification.
 @return An instance of the CTXMAMNotification object with the specified source and message.
 */
+ (instancetype) notificationWithSource:(CTXMAMNotificationSource)source andMessage:(NSString *)message andError:(NSError *)error;
/*!
 @brief initWithSource:andMessage initializer intializes a new notification object with the specified source and message.
 @param source The source of the notification.
 @param message The message which describes the notification.
 @return An instance of the CTXMAMNotification object with the specified source and message.
 */
- (instancetype) initWithSource:(CTXMAMNotificationSource)source andMessage:(NSString *)message;
/*!
 @brief initWithSource:andMessage:andError initializer intializes a new notification object with the specified source and message.
 @param source The source of the notification.
 @param message The message which describes the notification.
 @param error The error which is to be associates with the notification.
 @return An instance of the CTXMAMNotification object with the specified source and message.
 */
- (instancetype) initWithSource:(CTXMAMNotificationSource)source andMessage:(NSString *)message andError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END

#endif /* __CTXMAMNOTIFICATION_H__ */
