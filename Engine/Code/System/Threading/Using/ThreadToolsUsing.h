///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:17)

#ifndef SYSTEM_THREADING_THREAD_TOOLS_USING_H
#define SYSTEM_THREADING_THREAD_TOOLS_USING_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ProcThreadAttributeList = _PROC_THREAD_ATTRIBUTE_LIST;
    using ProcThreadAttributeListPtr = LPPROC_THREAD_ATTRIBUTE_LIST;

#else  // !SYSTEM_PLATFORM_WIN32

    struct ProcThreadAttributeList
    {
    };
    using ProcThreadAttributeListPtr = ProcThreadAttributeList*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_TOOLS_USING_H