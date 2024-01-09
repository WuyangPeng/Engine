/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:04)

#ifndef SYSTEM_HELPER_SGI_H
#define SYSTEM_HELPER_SGI_H

#if defined(__STL_CONFIG_H)

    //  通用 SGI STL:

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION 1

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "SGI 标准库版本 "

    #endif  // !TCRE_STDLIB

    #if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

        #include <unistd.h>

    #endif  // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

    #define TCRE_USE_SGI static_cast<void>(0)

#endif  // __STL_CONFIG_H

#endif  // SYSTEM_HELPER_SGI_H
