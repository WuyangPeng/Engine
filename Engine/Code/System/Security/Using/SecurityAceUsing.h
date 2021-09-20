///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/05/24 16:14)

#ifndef SYSTEM_SECURITY_SECURITY_ACE_USING_H
#define SYSTEM_SECURITY_SECURITY_ACE_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using AceHeader = ACE_HEADER;
    using AceHeaderPtr = PACE_HEADER;
    using AccessMask = ACCESS_MASK;
    using AccessAllowedAce = ACCESS_ALLOWED_ACE;
    constexpr WindowsDWord g_MaxDWord{ MAXDWORD };

#else  // !SYSTEM_PLATFORM_WIN32

    struct AceHeader
    {
        uint8_t AceType;
        uint8_t AceFlags;
        uint16_t AceSize;
    };
    using AceHeaderPtr = AceHeader*;

    using AccessMask = uint32_t;
    struct AccessAllowedAce
    {
        AceHeader Header;
        AccessMask Mask;
        uint32_t SidStart;
    };
    constexpr uint32_t g_MaxDWord{ 0xffffffff };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_SECURITY_ACE_USING_H