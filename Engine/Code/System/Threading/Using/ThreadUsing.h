///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:17)

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
    using ThreadStartRoutine = WindowsDWord (*)(void* threadParameter);

    using StartAddress = unsigned(__stdcall*)(void*);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_THREAD_USING_H