///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/25 13:56)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_USING_H
#define SYSTEM_THREADING_FIBER_TOOLS_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = PFLS_CALLBACK_FUNCTION;
    constexpr WindowsDWord g_FlsOutOfIndexes{ FLS_OUT_OF_INDEXES };
    using FiberStartRoutine = LPFIBER_START_ROUTINE;

#else  // !SYSTEM_PLATFORM_WIN32

    using FlsCallbackFunction = void (*)(void* flsData);
    constexpr WindowsDWord g_FlsOutOfIndexes{ 0xFFFFFFFF };
    using FiberStartRoutine = void (*)(void* fiberParameter);

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_THREADING_FIBER_TOOLS_USING_H