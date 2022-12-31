///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/02 16:27)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class StandardHandle : uint32_t
    {
        Input = STD_INPUT_HANDLE,
        Output = STD_OUTPUT_HANDLE,
        Error = STD_ERROR_HANDLE,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class StandardHandle : uint32_t
    {
        Input = static_cast<uint32_t>(-10),
        Output = static_cast<uint32_t>(-11),
        Error = static_cast<uint32_t>(-12),
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CONSOLE_CONSOLE_HANDLE_FLAGS_H
