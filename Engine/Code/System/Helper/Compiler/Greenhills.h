/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:14)

#ifndef SYSTEM_HELPER_GREENHILLS_H
#define SYSTEM_HELPER_GREENHILLS_H

#ifdef __ghs

    // Greenhills C++ 编译器设置：

    // 版本检查：
    #if (__ghs < 0)

        #error "编译器未配置"

    #endif  // __ghs < 0

    #if (0 < __ghs)

        #error "未知的编译器版本"

    #endif  // 0 < __ghs

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_GREENHILLS

        #define TCRE_USE_GREENHILLS 1

    #endif  // TCRE_USE_GREENHILLS

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __ghs

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Greenhills C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __ghs

#endif  // SYSTEM_HELPER_GREENHILLS_H
