///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:11)

#ifndef SYSTEM_HELPER_INTEL_H
#define SYSTEM_HELPER_INTEL_H

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)

    // Intel 编译器设置：

    #if defined(__INTEL_COMPILER) && (1500 <= __INTEL_COMPILER) && (defined(_MSC_VER) || defined(__GNUC__))

        #ifdef _MSC_VER

            #include "Visualc.h"

            #undef MSVC_VERSION
            #undef MSVC_FULL_VERSION

        #else  // !_MSC_VER

            #include "Gcc.h"

            #undef GCC_VERSION
            #undef FALLTHROUGH

            #if (1800 <= __INTEL_COMPILER) && (201703 <= __cplusplus)

                #define FALLTHROUGH [[fallthrough]]

            #endif  // (1800 <= __INTEL_COMPILER) && (201703 <= __cplusplus)

        #endif  // _MSC_VER

        #undef TCRE_SYSTEM_COMPILER
        #undef TCRE_COMPILER_VERSION

    #endif  // defined(__INTEL_COMPILER) && (1500 <= __INTEL_COMPILER) && (defined(_MSC_VER) || defined(__GNUC__))

    #if defined(__INTEL_COMPILER)

        #if __INTEL_COMPILER == 9999

            // Intel bug 在 12.1.
            #define TCRE_COMPILER_VERSION 1200

        #else  // __INTEL_COMPILER != 9999

            #define TCRE_COMPILER_VERSION __INTEL_COMPILER

        #endif  // __INTEL_COMPILER == 9999

    #elif defined(__ICL)

        #define TCRE_COMPILER_VERSION __ICL

    #elif defined(__ICC)

        #define TCRE_COMPILER_VERSION __ICC

    #elif defined(__ECC)

        #define TCRE_COMPILER_VERSION __ECC

    #endif  // __INTEL_COMPILER

    #ifdef __GNUC__

        #define INTEL_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

    #endif  // __GNUC__

    // 通过比较“icpc -dM -E”的输出确定的标志来确定有没有“-std=c++0x”
    #if (!(defined(_WIN32) || defined(_WIN64)) && defined(__STDC_HOSTED__) && (__STDC_HOSTED__ && (TCRE_COMPILER_VERSION <= 1200))) || defined(__GXX_EXPERIMENTAL_CPP0X__) || defined(__GXX_EXPERIMENTAL_CXX0X__)

        #define SYSTEM_INTEL_STDCXX0X

    #endif  // (!(defined(_WIN32) || defined(_WIN64)) && defined(__STDC_HOSTED__) && (__STDC_HOSTED__ && (COMPILER_VERSION <= 1200))) || defined(__GXX_EXPERIMENTAL_CPP0X__) || defined(__GXX_EXPERIMENTAL_CXX0X__)

    #if defined(_MSC_VER) && (1600 <= _MSC_VER)

        #define SYSTEM_INTEL_STDCXX0X

    #endif  // defined(_MSC_VER) && (_MSC_VER >= 1600)

    #if !defined(TCRE_SYSTEM_COMPILER)

        #if defined(SYSTEM_INTEL_STDCXX0X)

            #define TCRE_SYSTEM_COMPILER "Intel C++ C++0x 模式版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

        #else  // !SYSTEM_INTEL_STDCXX0X

            #define TCRE_SYSTEM_COMPILER "Intel C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

        #endif  // SYSTEM_INTEL_STDCXX0X

    #endif  // TCRE_SYSTEM_COMPILER

    #ifndef TCRE_USE_INTEL

        #define TCRE_USE_INTEL TCRE_COMPILER_VERSION

    #endif  // TCRE_USE_INTEL

    #if defined(_WIN32) || defined(_WIN64)

        #define TCRE_INTEL_WIN TCRE_USE_INTEL

    #else  // !defined(_WIN32) && !defined(_WIN64)

        #define TCRE_INTEL_LINUX TCRE_USE_INTEL

    #endif  // defined(_WIN32) || defined(_WIN64)

    // 版本检查：我们不支持版本6.0之前的Intel：
    #if TCRE_COMPILER_VERSION < 600

        #error "编译器未设置"

    #endif  // TCRE_COMPILER_VERSION < 600

    #if (1700 < TCRE_COMPILER_VERSION)

        #error "未知的编译器"

    #endif  // (1700 < COMPILER_VERSION)

    #if (TCRE_COMPILER_VERSION < 1200)

        #undef SYSTEM_CPP_STANDARD

        #if defined(__CUDACC__)

            #if defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

                #define SYSTEM_CPP_STANDARD 11

            #else  // !defined(__GXX_EXPERIMENTAL_CXX0X__) && (__cplusplus < 201103L)

                #define SYSTEM_CPP_STANDARD 3

            #endif  // defined(__GXX_EXPERIMENTAL_CXX0X__) || (201103L <= __cplusplus)

        #endif  // __CUDACC__

    #endif  // (COMPILER_VERSION < 1200)

#endif  // defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)

#endif  // SYSTEM_HELPER_INTEL_H
