///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 16:53)

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