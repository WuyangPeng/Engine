/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/27 17:44)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_USING_H
#define SYSTEM_THREADING_FIBER_TOOLS_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = PFLS_CALLBACK_FUNCTION;
    constexpr WindowsDWord flsOutOfIndexes{ FLS_OUT_OF_INDEXES };
    using FiberStartRoutine = LPFIBER_START_ROUTINE;

#else  // !SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = void (*)(void* flsData);
    constexpr WindowsDWord flsOutOfIndexes{ 0xFFFFFFFF };
    using FiberStartRoutine = void (*)(void* fiberParameter);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_FIBER_TOOLS_USING_H