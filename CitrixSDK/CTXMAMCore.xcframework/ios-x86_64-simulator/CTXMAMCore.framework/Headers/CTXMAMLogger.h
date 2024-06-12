//
//  CTXMAMLogger.h
//  CTXMAMCore
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2021 Citrix Systems, Inc. All rights reserved.
//

/*!
 @header CTXMAMLogger.h
 Use the functions declared here to send messages to the Citrix Logging Facility.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

#import <Foundation/Foundation.h>

// Activity message classes
#define CTXMAMLOG_MSG_CRITICAL         1
#define CTXMAMLOG_MSG_ERROR            2
#define CTXMAMLOG_MSG_WARNING          3
#define CTXMAMLOG_MSG_INFO             4
#define CTXMAMLOG_MSG_DETAIL           5

//Log type
#define CTXMAMLOG_LOG_TYPE_ACTIVITY    1

/*!
 CTXMAMLOG_CriticalError convenience function logs the specified message as a Critical Error.
 @param source A string object which describes the source of the log message.
 @param fmt A standard format spcified string.
 */
#define CTXMAMLOG_CriticalError(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_MSG_CRITICAL, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
 CTXMAMLOG_Error convenience function logs the specified message as an Error.
 @param source A string object which describes the source of the log message.
 @param fmt A standard format spcified string.
 */
#define CTXMAMLOG_Error(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_MSG_ERROR, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
 CTXMAMLOG_Warn convenience function logs the specified message as a Warning.
 @param source A string object which describes the source of the log message.
 @param fmt A standard format spcified string.
 */
#define CTXMAMLOG_Warn(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_MSG_WARNING, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
 CTXMAMLOG_Info convenience function logs the specified message as Information.
 @param source A string object which describes the source of the log message.
 @param fmt A standard format spcified string.
 */
#define CTXMAMLOG_Info(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_MSG_INFO, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

/*!
 CTXMAMLOG_Detail convenience function logs the specified message as Details.
 @param source A string object which describes the source of the log message.
 @param fmt A standard format spcified string.
 */
#define CTXMAMLOG_Detail(source, fmt,...) \
CTXMAMLOG_Message(source, CTXMAMLOG_MSG_DETAIL, CTXMAMLOG_LOG_TYPE_ACTIVITY, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN


/*!
 CTXMAMLOG_Initialize function initializes the logger.
 */
void CTXMAMLOG_Initialize(void);

/*!
 CTXMAMLOG_Detail function logs the specified message as Details.
 @param source A string object which describes the source of the log message.
 @param file A C string pointer which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param func A C string pointer which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param line An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
void CTXMAMLOG_Message(NSString * source, int level, int logType, const char * file, const char * func, int line, NSString * fmt, ...) NS_FORMAT_FUNCTION(7, 8);

/*!
 This is a wrapper for the CTXLOG calls and is used to provide interfaces used for logging messages into the Citrix CTXMAM Framework logging facility.
 */
@interface CTXMAMLogger : NSObject

/*!
 CTXMAMLog_Initialize function initializes the logger.
 */
+(void) CTXMAMLog_Initialize;
/*!
 CTXMAMLog_CriticalErrorFrom function logs the specified message as a Critical Error.
 @param source A string object which describes the module name of the log message.
 @param fileName A string object which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param functionName A string object which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param lineNumber An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
+(void) CTXMAMLog_CriticalErrorFrom:   (NSString *)source andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int) lineNumber withFormat:(NSString *)fmt, ... NS_FORMAT_FUNCTION(5, 6);
/*!
 CTXMAMLog_ErrorFrom function logs the specified message as an Error.
 @param source A string object which describes the source of the log message.
 @param fileName A string object which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param functionName A string object which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param lineNumber An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
+(void) CTXMAMLog_ErrorFrom:           (NSString *)source andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int) lineNumber withFormat:(NSString *)fmt, ... NS_FORMAT_FUNCTION(5, 6);
/*!
 CTXMAMLog_WarningFrom function logs the specified message as a Warning.
 @param source A string object which describes the source of the log message.
 @param fileName A string object which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param functionName A string object which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param lineNumber An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
+(void) CTXMAMLog_WarningFrom:         (NSString *)source andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int) lineNumber withFormat:(NSString *)fmt, ... NS_FORMAT_FUNCTION(5, 6);
/*!
 CTXMAMLog_InfoFrom function logs the specified message as Information.
 @param source A string object which describes the source of the log message.
 @param fileName A string object which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param functionName A string object which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param lineNumber An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
+(void) CTXMAMLog_InfoFrom:            (NSString *)source andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int) lineNumber withFormat:(NSString *)fmt, ... NS_FORMAT_FUNCTION(5, 6);
/*!
 CTXMAMLog_DetailFrom function logs the specified message as Details.
 @param source A string object which describes the source of the log message.
 @param fileName A string object which contains the name of the source file where the message resides - use __FILE__ macro to get the current file name.
 @param functionName A string object which contains the name of the function where the message comes from - use __FUNCTION__ macro to get the current function name.
 @param lineNumber An int which represents the line number of the source file where the message resides - use __LINE__ macro to get the current line number.
 @param fmt A standard format string which contains the customized message to be logged out to the logger.
 */
+(void) CTXMAMLog_DetailFrom:          (NSString *)source andFile:(nullable NSString *)fileName andFunction:(nullable NSString *)functionName atLine:(int) lineNumber withFormat:(NSString *)fmt, ... NS_FORMAT_FUNCTION(5, 6);

@end

NS_ASSUME_NONNULL_END
