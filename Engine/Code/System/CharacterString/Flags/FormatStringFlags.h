//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:15)

#ifndef SYSTEM_CHARACTER_STRING_FORMAT_STRING_FLAGS_H
#define SYSTEM_CHARACTER_STRING_FORMAT_STRING_FLAGS_H

#include "System/Helper/EnumMacro.h"
#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32
    #include <Strsafe.h>
#endif  // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class StringSafe
    {
        IgnoreNulls = STRSAFE_IGNORE_NULLS,
        FillBehindNull = STRSAFE_FILL_BEHIND_NULL,
        FillOnFailure = STRSAFE_FILL_ON_FAILURE,
        NullOnFailure = STRSAFE_NULL_ON_FAILURE,
        NoTruncation = STRSAFE_NO_TRUNCATION,

        ValidFlags = STRSAFE_VALID_FLAGS,

        FillByte = 0x000000FF,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class StringSafe
    {
        IgnoreNulls = 0x00000100,
        FillBehindNull = 0x00000200,
        FillOnFailure = 0x00000400,
        NullOnFailure = 0x00000800,
        NoTruncation = 0x00001000,

        ValidFlags = (0x000000FF | FillBehindNull | FillBehindNull | FillOnFailure | NullOnFailure | NoTruncation),

        FillByte = 0x000000FF,
    };

#endif  // SYSTEM_PLATFORM_WIN32

    // 定义operator &和|运算符。
    ENUM_ANDABLE_OPERATOR_DEFINE(StringSafe);
    ENUM_ORABLE_OPERATOR_DEFINE(StringSafe);
}

#endif  // SYSTEM_CHARACTER_STRING_FORMAT_STRING_FLAGS_H
