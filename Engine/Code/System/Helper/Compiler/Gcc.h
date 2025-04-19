/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 17:27)

#ifndef SYSTEM_HELPER_GCC_H
#define SYSTEM_HELPER_GCC_H

#if defined(__GNUC__) && !defined(__ibmxl__)

    /// GNU C++ 编译器设置：

    #ifndef TCRE_USE_GCC

        #define TCRE_USE_GCC __GNUC__

    #endif  // TCRE_USE_GCC

    #ifndef GCC_VERSION

        #define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

    #endif  // GCC_VERSION

    /// 版本检查：
    #if (GCC_VERSION < 30300)

        #error "编译器未配置"

    #endif  // GCC_VERSION < 30300

    #if !defined(__CUDACC__)

        #ifndef TCRE_COMPILER_VERSION

            #define TCRE_COMPILER_VERSION __GNUC__

        #endif  // TCRE_COMPILER_VERSION

    #endif  // __CUDACC__

    #ifndef TCRE_SYSTEM_COMPILER

        #ifdef __GXX_CONCEPTS__

            /// ConceptGCC 编译器：http://www.generic-programming.org/software/ConceptGCC/
            #define TCRE_SYSTEM_COMPILER "ConceptGCC 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

        #else  // !__GXX_CONCEPTS__

            #define TCRE_SYSTEM_COMPILER "GNU C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

        #endif  // __GXX_CONCEPTS__

    #endif  // TCRE_SYSTEM_COMPILER

    #ifndef SYSTEM_CPP_STANDARD

        #if defined(__cpp_if_constexpr) && (202002L <= __cplusplus)

            #define SYSTEM_CPP_STANDARD 20

        #elif (201606L <= __cplusplus)

            #define SYSTEM_CPP_STANDARD 17

        #elif (201300L <= __cplusplus)

            #define SYSTEM_CPP_STANDARD 14

        #elif defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

            #define SYSTEM_CPP_STANDARD 11

        #else  // !defined(__GXX_EXPERIMENTAL_CXX0X__) && (__cplusplus < 201103L)

            #define SYSTEM_CPP_STANDARD 3

        #endif  // defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

    #endif  // SYSTEM_CPP_STANDARD

    #include <cstddef>
    #include <cstdint>

    #if (4 <= __GNUC__) && (SYSTEM_CPP_STANDARD < 17)

        #define MAYBE_UNUSED __attribute__((__unused__))

    #endif  // (4 <= __GNUC__) && (SYSTEM_CPP_STANDARD < 17)

    #if (7 <= __GNUC__) && (SYSTEM_CPP_STANDARD < 17)

        #define FALLTHROUGH __attribute__((fallthrough))

    #endif  // (7 <= __GNUC__) && (SYSTEM_CPP_STANDARD < 17)

    /// 分支预测提示
    #define TCRE_LIKELY(x) __builtin_expect(x, 1)
    #define TCRE_UNLIKELY(x) __builtin_expect(x, 0)

    #if SYSTEM_CPP_STANDARD < 14

        #define SYSTEM_DEPRECATED(x) __attribute__((deprecated))

    #endif  // SYSTEM_CPP_STANDARD < 14

#endif  // defined(__GNUC__) && !defined(__ibmxl__)

#endif  // SYSTEM_HELPER_GCC_H
