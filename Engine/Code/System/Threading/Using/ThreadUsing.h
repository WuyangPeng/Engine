///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 16:53)

#ifndef SYSTEM_THREADING_THREAD_USING_H
#define SYSTEM_THREADING_THREAD_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using ThreadHandle = HANDLE;
    using ThreadHandlePtr = PHANDLE;
    using ThreadStartRoutine = PTHREAD_START_ROUTINE;

    using StartAddress = unsigned(__stdcall*)(void*);

#else  // !SYSTEM_PLATFORM_WIN32

    using ThreadHandle = pthread_t;
    using ThreadHandlePtr = ThreadHandle*;
    using ThreadStartRoutine = WindowsDWord(*)(void* threadParameter);

    using StartAddress = unsigned(__stdcall*)(void*);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_USING_H