//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 14:33)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_USING_H
#define SYSTEM_THREADING_FIBER_TOOLS_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = PFLS_CALLBACK_FUNCTION;
    constexpr WindowDWord g_FlsOutOfIndexes{ FLS_OUT_OF_INDEXES };
    using FiberStartRoutine = LPFIBER_START_ROUTINE;

#else  // !SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = void (*)(void* flsData);
    constexpr WindowDWord g_FlsOutOfIndexes{ 0xFFFFFFFF };
    using FiberStartRoutine = void (*)(void* fiberParameter);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_FIBER_TOOLS_USING_H