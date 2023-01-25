///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.0 (2023/01/23 23:11)

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