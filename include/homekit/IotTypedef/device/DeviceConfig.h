/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   DeviceConfig.h
 *
 * @remark
 *
 */

#ifndef __DEVICE_CONFIG_H__
#define __DEVICE_CONFIG_H__

#include "tiny_base.h"
#include "common/typedef_api.h"
#include <constraint/typedef_constraint.h>
#include <tiny_lor.h>

TINY_BEGIN_DECLS


typedef struct _DeviceConfig
{
    char                ip[TINY_IP_LEN + 1];
    uint16_t            port;

    char                pin[DEVICE_PIN_LENGTH + 1];
    char                id[DEVICE_ID_LENGTH + 1];       // id
    char                name[DEVICE_NAME_LENGTH + 1];   // name
    char                model[DEVICE_MODEL_LENGTH + 1]; // md

    /**
     * Current configuration number. Required.
     * Updates only when an accessory, service, or characteristic is
     * added or removed on the accessory server.
     * This must have a range of 1 - 4294967295 and wrap to 1 when it overflows.
     * This value must persist across reboots, power cycles, etc.
     */
    uint32_t            configurationNumber;        // c#

    /**
     * Accessory Categories
     * 1.   Other
     * 2.   Bridge
     * 3.   Fan
     * 4.   Garage
     * 5.   Lightbulb
     * 6.   Door Lock
     * 7.   Outlet
     * 8.   Switch
     * 9.   Thermostat
     * 10.  Sensor
     * 11.  Security System
     * 12.  Door
     * 13.  Window
     * 14.  Window Covering
     * 15.  Programmable Switch
     * 16.  Range Extender
     * 17+  Reserved
     */
    uint32_t            categoryIdentifier;         // ci

    /**
     * Feature flags.
     * Mask         Bit     Description
     * -------------------------------------------------------------------------------------
     * 0x01         1       Supports HAP Pairing. This flag is required for all accessories.
     * 0x02 - 0x80  2-8     Reserved.
     */
    uint32_t            featureFlags;               // ff

    /**
     * Current state number. Required.
     * This must have a value of "1".
     */
    uint32_t            stateNumber;                // s#

    /**
     * Status flags.
     * Mask         Bit     Description
     * -------------------------------------------------------------------------------------
     * 0x01         1       Accessory has not been paired with any controllers.
     * 0x02         2       Accessory has not been configured to join a Wi-Fi network.
     * 0x04         3       A problem has been detected on the accessory.
     * 0x08 - 0x80  4-8     Reserved.
     */
    uint32_t            statusFlags;                // sf

    /**
     * Protocol version string <major>.<minor>. Required if value is not "1.0"
     */
    uint32_t            protocolVersion;
} DeviceConfig;

typedef void (* DeviceConfigurationInitializer)(DeviceConfig *thiz, void *ctx);

//TYPEDEF_API DeviceConfig * DeviceConfig_New(void);
//TYPEDEF_API void DeviceConfig_Delete(DeviceConfig *thiz);

TYPEDEF_API
TINY_LOR
TinyRet DeviceConfig_Construct(DeviceConfig *thiz);

TYPEDEF_API
TINY_LOR
void DeviceConfig_Dispose(DeviceConfig *thiz);

TYPEDEF_API
TINY_LOR
void DeviceConfig_Initialize(DeviceConfig *thiz, DeviceConfigurationInitializer initializer, void *ctx);

TYPEDEF_API
TINY_LOR
void DeviceConfig_Copy(DeviceConfig *dst, DeviceConfig *src);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetIp(DeviceConfig *thiz, const char *ip);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetPort(DeviceConfig *thiz, uint16_t port);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetName(DeviceConfig *thiz, const char *name);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetId(DeviceConfig *thiz, const char *id);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetModelName(DeviceConfig *thiz, const char *model);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetConfigurationNumber(DeviceConfig *thiz, uint32_t value);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetCurrentStateNumber(DeviceConfig *thiz, uint32_t value);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetFeatureFlags(DeviceConfig *thiz, uint32_t value);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetCategoryIdentifier(DeviceConfig *thiz, uint32_t value);

TYPEDEF_API
TINY_LOR
void DeviceConfig_SetPinCode(DeviceConfig *thiz, const char *pin);


TINY_END_DECLS

#endif /* __DEVICE_CONFIG_H__ */
