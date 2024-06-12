//
//  CTXMAMUserAttributes.h
//  CTXMAMAppCore
//
//  Copyright © 2021 Citrix Systems Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @header CTXMAMUserAttributes.h
 Including this header into your source files will help in getting different user attributes from CEM into your project.
 @copyright Citrix Systems, Inc.
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */
@interface CTXMAMUserAttributes : NSObject

/*!
 @brief A property which holds the LDAP User Principal Name. Example: user1@example
 @discussion This property requires client property configuration on Citrix Endpoint Management server.
             SEND_LDAP_ATTRIBUTES should be configured as documented in https://docs.citrix.com/en-us/citrix-endpoint-management/advanced-concepts/deployment/client-properties.html
 */
@property (nonatomic, readonly, strong) NSString * _Nullable ldapUserPrincipalName;

/*!
 @brief A property which holds the LDAP SAM Account Name. Example:  user1
 @discussion This property requires client property configuration on Citrix Endpoint Management server.
             SEND_LDAP_ATTRIBUTES should be configured as documented in https://docs.citrix.com/en-us/citrix-endpoint-management/advanced-concepts/deployment/client-properties.html
 */
@property (nonatomic, readonly, strong) NSString * _Nullable ldapSAMAccountName;

/*!
 @brief A property which holds the LDAP Display Name. Example: User One
 @discussion This property requires client property configuration on Citrix Endpoint Management server.
             SEND_LDAP_ATTRIBUTES should be configured as documented in https://docs.citrix.com/en-us/citrix-endpoint-management/advanced-concepts/deployment/client-properties.html
 */
@property (nonatomic, readonly, strong) NSString * _Nullable ldapDisplayName;

/*!
 @brief A property which holds the LDAP Email. Example: user1@example.com
 @discussion This property requires client property configuration on Citrix Endpoint Management server.
             SEND_LDAP_ATTRIBUTES should be configured as documented in https://docs.citrix.com/en-us/citrix-endpoint-management/advanced-concepts/deployment/client-properties.html
 */
@property (nonatomic, readonly, strong) NSString * _Nullable ldapMail;

@end

NS_ASSUME_NONNULL_END
