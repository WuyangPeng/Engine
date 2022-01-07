///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:47)

#ifndef SYSTEM_FILE_MANAGE_FILE_USING_H
#define SYSTEM_FILE_MANAGE_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

    namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr WindowsDWord g_InvalidFileSize{ INVALID_FILE_SIZE };
    constexpr WindowsDWord g_InvalidSetFilePointer{ INVALID_SET_FILE_POINTER };

    using FileTime = FILETIME;
    using FileTimePtr = LPFILETIME;

#else  // !SYSTEM_PLATFORM_WIN32

    constexpr WindowsDWord g_InvalidFileSize{ 0xFFFFFFFF };
    constexpr WindowsDWord g_InvalidSetFilePointer{ static_cast<WindowsDWord>(-1) };

    struct FileTime
    {
        uint32_t dwLowDateTime;
        uint32_t dwHighDateTime;
    };

    using FileTimePtr = FileTime*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGE_FILE_USING_H