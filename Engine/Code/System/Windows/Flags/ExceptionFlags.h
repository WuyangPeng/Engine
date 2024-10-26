/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 16:21)

#ifndef SYSTEM_WINDOWS_EXCEPTION_FLAGS_H
#define SYSTEM_WINDOWS_EXCEPTION_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class Exception
    {
        ExecuteHandler = EXCEPTION_EXECUTE_HANDLER,
        ContinueSearch = EXCEPTION_CONTINUE_SEARCH,
        ContinueExecution = EXCEPTION_CONTINUE_EXECUTION,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class Exception
    {
        ExecuteHandler = 1,
        ContinueSearch = 0,
        ContinueExecution = -1,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_WINDOWS_EXCEPTION_FLAGS_H
