///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/03 0:50)

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
