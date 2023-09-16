///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 11:22)

#ifndef SYSTEM_HELPER_WIN32_H
#define SYSTEM_HELPER_WIN32_H

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

    //  Win32 具体配置选项：

    // 微软Windows平台
    #define TCRE_SYSTEM_PLATFORM "Win32"
    #define SYSTEM_PLATFORM_WIN32 static_cast<void>(0)

    // 获取有关MinGW运行时的信息，即__MINGW32_ * VERSION。
    #if defined(__MINGW32__)

        #include <_mingw.h>

    #endif  // defined(__MINGW32__)

    #ifndef _WIN32

        #define _WIN32 static_cast<void>(0)

    #endif  // _WIN32

    #ifndef WIN32

        #define WIN32 static_cast<void>(0)

    #endif  // WIN32

    #ifndef __WIN32__

        #define __WIN32__ static_cast<void>(0)

    #endif  // __WIN32__

    #define SYSTEM_LITTLE_ENDIAN static_cast<void>(0)

    // 禁用各种子系统在 windows.h.
    #ifndef WIN32_LEAN_AND_MEAN

        #define WIN32_LEAN_AND_MEAN 1

    #endif  // WIN32_LEAN_AND_MEAN

    // 禁用windows.h中的“min”和“max”宏，它与std::numeric_limits<type>::max()冲突。
    #ifndef NOMINMAX

        #define NOMINMAX static_cast<void>(0)

    #endif  // NOMINMAX

#endif  // defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

#endif  // SYSTEM_HELPER_WIN32_H
