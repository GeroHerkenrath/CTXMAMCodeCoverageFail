//
//  CTXMAMConfigManager.h
//  CTXMAMConfigManager
//
//  Citrix iOS MAM SDK Public Header
//  Copyright © 2018 - 2021 Citrix Systems, Inc. All rights reserved.
//

/*!
 @header CTXMAMConfigManager
 Use the functions declared here to store and retrieve data from secure storage.
 @copyright Citrix Systems, Inc.
 @updated 2019-03-05
 @meta http-equiv=”refresh” content=”0;http://www.citrix.com”
 */

#import <Foundation/Foundation.h>

/*!
 @brief This is the class is the main configuration class for your application.
 It contains methods for storing and retrieving custom configurations.
 */
@interface CTXMAMConfigManager : NSObject
{
    
}

/*!
 @brief initializes the class, this function is not available for consumption please use sharedConfigManager in order to obtain an instance of this class.
 */
-(instancetype) init NS_UNAVAILABLE;
+(instancetype) new NS_UNAVAILABLE;

/*!
 @brief the singleton of the CTXMAMConfigManager class.
 @returns An instance of the CTXMAMConfigManager class.
 */
+(CTXMAMConfigManager *) sharedConfigManager;

#pragma mark Local Configuration Storage APIs
/*!
 @brief getConfigurationAsStringForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSString *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSString *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSString *)     getConfigurationAsStringForKey:     (NSString *) config defaultValue: (NSString *)     defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsNumberForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSNumber *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSNumber *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSNumber *)     getConfigurationAsNumberForKey:     (NSString *) config defaultValue: (NSNumber *)     defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDataForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSData *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSData *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSData *)       getConfigurationAsDataForKey:       (NSString *) config defaultValue: (NSData *)       defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDictionaryForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSDictionary *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSDictionary *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSDictionary *) getConfigurationAsDictionaryForKey: (NSString *) config defaultValue: (NSDictionary *) defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsIntegerForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSInteger) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSInteger) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSInteger)      getConfigurationAsIntegerForKey:    (NSString *) config defaultValue: (NSInteger)      defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDoubleForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (double) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (double) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(double)         getConfigurationAsDoubleForKey:     (NSString *) config defaultValue: (double)         defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsBoolForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (BOOL) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (BOOL) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(BOOL)           getConfigurationAsBoolForKey:       (NSString *) config defaultValue: (BOOL)           defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsObjectForKey function retrieves the data associated with the specified configuration name.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The id of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(id)             getConfigurationAsObjectForKey:     (NSString *) config defaultValue: (id)             defaultValue outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param stringValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config stringValue:  (NSString *)     stringValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param numberValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config numberValue:  (NSNumber *)     numberValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param dataValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config dataValue:    (NSData *)       dataValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param dictValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config dictValue:    (NSDictionary *) dictValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param intValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config intValue:     (NSInteger)      intValue     outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param doubleValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config doubleValue:  (double)         doubleValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param boolValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config boolValue:    (BOOL)           boolValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey function saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param objectValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setConfigurationForKey:             (NSString *) config objectValue:  (id)             objectValue  outError:    (NSError **) error;
/*!
 @brief removeConfigurationForKey function removes the data associated with the specified configuration name from the secure storage.
 @param config A string object which describes the data to be removed.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if removing the data was successful, otherwise NO.
 */
-(id)             removeConfigurationForKey:          (NSString *) config outError:     (NSError **)     error;
#pragma mark -
#pragma mark Shared Configuration Storage APIs
/*!
 @brief getConfigurationAsStringForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSString *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSString *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSString *)     getSharedConfigurationAsStringForKey:     (NSString *) config defaultValue: (NSString *)     defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsNumberForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSNumber *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSNumber *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSNumber *)     getSharedConfigurationAsNumberForKey:     (NSString *) config defaultValue: (NSNumber *)     defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDataForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSData *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSData *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSData *)       getSharedConfigurationAsDataForKey:       (NSString *) config defaultValue: (NSData *)       defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDictionaryForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSDictionary *) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSDictionary *) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSDictionary *) getSharedConfigurationAsDictionaryForKey: (NSString *) config defaultValue: (NSDictionary *) defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsIntegerForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (NSInteger) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (NSInteger) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(NSInteger)      getSharedConfigurationAsIntegerForKey:    (NSString *) config defaultValue: (NSInteger)      defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsDoubleForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (double) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (double) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(double)         getSharedConfigurationAsDoubleForKey:     (NSString *) config defaultValue: (double)         defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsBoolForKey is a convenience function which retrieves the data associated with the specified configuration name and returns as a (BOOL) type.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The (BOOL) representation of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(BOOL)           getSharedConfigurationAsBoolForKey:       (NSString *) config defaultValue: (BOOL)           defaultValue outError:    (NSError **) error;
/*!
 @brief getConfigurationAsObjectForKey function retrieves the data associated with the specified configuration name.
 @param config A string object which describes the saved data.
 @param defaultValue The value to be returned in case the specified configuration can not be found in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The id of the object found in the secure storage if found, otherwise the value passed to the defaultValue parameter is returned.
 */
-(id)             getSharedConfigurationAsObjectForKey:     (NSString *) config defaultValue: (id)             defaultValue outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param stringValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config stringValue:  (NSString *)     stringValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param numberValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config numberValue:  (NSNumber *)     numberValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param dataValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config dataValue:    (NSData *)       dataValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param dictValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config dictValue:    (NSDictionary *) dictValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param intValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config intValue:     (NSInteger)      intValue     outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param doubleValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config doubleValue:  (double)         doubleValue  outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey is a convenience function which saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param boolValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config boolValue:    (BOOL)           boolValue    outError:    (NSError **) error;
/*!
 @brief setConfigurationForKey function saves the data associated with the specified configuration name.
 @param config A string object which describes the data being saved.
 @param objectValue The value to be saved in the secure storage.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if saving the object was successful, otherwise NO.
 @discussion If a configuration name which already exists in the secure storage is passed then the stored value is overwritten by the new value passed.
 */
-(BOOL)           setSharedConfigurationForKey:             (NSString *) config objectValue:  (id)             objectValue  outError:    (NSError **) error;
/*!
 @brief removeConfigurationForKey function removes the data associated with the specified configuration name from the secure storage.
 @param config A string object which describes the data to be removed.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns YES if removing the data was successful, otherwise NO.
 */
-(id)             removeSharedConfigurationForKey:          (NSString *) config outError:     (NSError **)     error;
#pragma mark -
#pragma mark Custom Policy APIs

/*!
 @brief getPolicyValueForKey function will retrieve the custom policy value or client property for the specified key.
 @param key A string that represents the key for the policy of the value which is to be retrieved.
 @param error An out parameter where an error will be saved in case one occurs.
 @returns The id of the value for the policy which was retrieved. This value has to be cast to the type of the value for the specified policy.
 @discussion For boolean, int, float, and similar values, use NSNumber for casting the value.
 */
-(id)             getPolicyValueForKey:                     (NSString *) key    outError:     (NSError **)     error;

@end
