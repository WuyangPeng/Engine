///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/02 16:06)

#ifndef SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H
#define SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H

#include "System/Helper/EnumOperator.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class DesiredAccessGeneric : uint32_t
    {
        Read = GENERIC_READ,
        Write = GENERIC_WRITE,
        Execute = GENERIC_EXECUTE,
        All = GENERIC_ALL,
        ReadAndWrite = Read | Write,
    };

    enum class ConsoleScreenBufferShareMode
    {
        Read = FILE_SHARE_READ,
        Write = FILE_SHARE_WRITE,
        Delete = FILE_SHARE_DELETE,
        ReadAndWrite = Read | Write,
    };

    enum class ConsoleScreenBuffer
    {
        TextModeBuffer = CONSOLE_TEXTMODE_BUFFER,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class DesiredAccessGeneric
    {
        Read = 0x80000000L,
        Write = 0x40000000L,
        Execute = 0x20000000L,
        All = 0x10000000L,
        ReadAndWrite = Read | Write,
    };

    enum class ConsoleScreenBufferShareMode
    {
        Read = 0x00000001,
        Write = 0x00000002,
        Delete = 0x00000004,
        ReadAndWrite = Read | Write,
    };

    enum class ConsoleScreenBuffer
    {
        TextModeBuffer = 1,
    };

#endif  // SYSTEM_PLATFORM_WIN32

}

#endif  // SYSTEM_CONSOLE_CONSOLE_SCREEN_BUFFER_FLAGS_H
