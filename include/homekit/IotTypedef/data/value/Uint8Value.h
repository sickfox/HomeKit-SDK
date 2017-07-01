/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   Uint8Value.h
 *
 * @remark
 *
 */

#ifndef __UINT8_VALUE_H__
#define __UINT8_VALUE_H__

#include "common/typedef_api.h"
#include "tiny_base.h"

TINY_BEGIN_DECLS


typedef struct _Uint8Value
{
    uint8_t             value;
    bool                hasRange;
    struct
    {
        uint8_t         max;
        uint8_t         min;
        uint8_t         step;
        bool            hasStep;
    } range;
} Uint8Value;

TYPEDEF_API TinyRet Uint8Value_SetRange(Uint8Value *thiz, uint8_t min, uint8_t max, uint8_t step);
TYPEDEF_API TinyRet Uint8Value_Set(Uint8Value *thiz, uint8_t value);


TINY_END_DECLS

#endif /* __UINT8_VALUE_H__ */
