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

    #if __cplusplus >= 202002L

        #define SYSTEM_CPP_STANDARD 20

    #elif __cplusplus >= 201703L

        #define SYSTEM_CPP_STANDARD 17

    #elif __cplusplus >= 201402L

        #define SYSTEM_CPP_STANDARD 14

    #elif __cplusplus >= 201103L

        #define SYSTEM_CPP_STANDARD 11

    #else  // __cplusplus < 201103L

        #define SYSTEM_CPP_STANDARD 3

    #endif  // __cplusplus

    /// 自第一个版本以来，Clang一直支持“unused”属性。
    #define MAYBE_UNUSED __attribute__((__unused__))

    /// FALLTHROUGH宏可用于注释switch标签之间的隐式的fall-through。
    #if 201103L <= __cplusplus && defined(__has_warning)

        #if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

            #define FALLTHROUGH [[clang::fallthrough]]

        #endif  //  __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")

    #endif  // 201103L <= __cplusplus && defined(__has_warning)

#endif  // defined(__clang__) && !defined(__ibmxl__) && !defined(__CODEGEARC__)

#endif  // SYSTEM_HELPER_CLANG_H
