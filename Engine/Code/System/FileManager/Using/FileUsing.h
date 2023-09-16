///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:14)

#ifndef SYSTEM_FILE_MANAGER_FILE_USING_H
#define SYSTEM_FILE_MANAGER_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr WindowsDWord gInvalidFileSize{ INVALID_FILE_SIZE };
    constexpr WindowsDWord gInvalidSetFilePointer{ INVALID_SET_FILE_POINTER };

    using FileTime = FILETIME;
    using FileTimePtr = LPFILETIME;

#else  // !SYSTEM_PLATFORM_WIN32

    constexpr WindowsDWord gInvalidFileSize{ 0xFFFFFFFF };
    constexpr WindowsDWord gInvalidSetFilePointer{ static_cast<WindowsDWord>(-1) };

    struct FileTime
    {
        uint32_t dwLowDateTime;
        uint32_t dwHighDateTime;
    };

    using FileTimePtr = FileTime*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGER_FILE_USING_H