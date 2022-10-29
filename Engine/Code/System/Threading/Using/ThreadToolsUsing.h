///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 0:03)

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