///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 10:42)

#ifndef SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H
#define SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using LookupPrivilegeLUID = LUID;
    using LookupPrivilegeLUIDPtr = PLUID;

#else  // !SYSTEM_PLATFORM_WIN32

    struct LookupPrivilegeLUID
    {
        WindowsDWord LowPart;
        WindowsLong HighPart;
    };
    using LookupPrivilegeLUIDPtr = LookupPrivilegeLUID*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_SECURITY_LOOKUP_PRIVILEGE_USING_H