/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：v0.0.0.1 (2025/08/14 17:18:01)

#ifndef SYSTEM_HELPER_CLANG_H
#define SYSTEM_HELPER_CLANG_H

/// Clang编译器设置：

#if defined(__clang__) && !defined(__ibmxl__) && !defined(__CODEGEARC__)

    #ifndef TCRE_USE_CLANG

        #define TCRE_USE_CLANG 1

    #endif  // TCRE_USE_CLANG

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __clang_version__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Clang 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // defined(__clang__) && !defined(__ibmxl__) && !defined(__CODEGEARC__)

#endif  // SYSTEM_HELPER_CLANG_H
