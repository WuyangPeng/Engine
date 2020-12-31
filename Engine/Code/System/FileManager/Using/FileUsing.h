//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:57)

#ifndef SYSTEM_FILE_MANAGE_FILE_USING_H
#define SYSTEM_FILE_MANAGE_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    constexpr WindowDWord g_InvalidFileSize{ INVALID_FILE_SIZE };
    constexpr WindowDWord g_InvalidSetFilePointer{ INVALID_SET_FILE_POINTER };

    using FileTime = FILETIME;
    using FileTimePtr = LPFILETIME;

#else  // !SYSTEM_PLATFORM_WIN32

    constexpr WindowDWord g_InvalidFileSize{ 0xFFFFFFFF };
    constexpr WindowDWord g_InvalidSetFilePointer{ static_cast<WindowDWord>(-1) };

    struct FileTime
    {
        uint32_t dwLowDateTime;
        uint32_t dwHighDateTime;
    };

    using FileTimePtr = FileTime*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_FILE_MANAGE_FILE_USING_H