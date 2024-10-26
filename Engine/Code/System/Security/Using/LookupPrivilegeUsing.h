/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:45)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using LookupPrivilegeLocallyUniqueIdentifier = LUID;
    using LookupPrivilegeLocallyUniqueIdentifierPtr = PLUID;

#else  // !SYSTEM_PLATFORM_WIN32

    struct LookupPrivilegeLocallyUniqueIdentifier
    {
        WindowsDWord LowPart;
        WindowsLong HighPart;
    };
    using LookupPrivilegeLocallyUniqueIdentifierPtr = LookupPrivilegeLocallyUniqueIdentifier*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H