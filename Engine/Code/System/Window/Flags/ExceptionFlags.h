//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 10:41)

#ifndef SYSTEM_WINDOW_EXCEPTION_FLAGS_H
#define SYSTEM_WINDOW_EXCEPTION_FLAGS_H

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

#endif  // SYSTEM_WINDOW_EXCEPTION_FLAGS_H
