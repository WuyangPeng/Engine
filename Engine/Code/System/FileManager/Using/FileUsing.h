/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 09:26)

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