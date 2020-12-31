//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:09)

#ifndef SYSTEM_HELPER_XLCPP_H
#define SYSTEM_HELPER_XLCPP_H

#if defined(__ibmxl__)

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_XLCPP
        #define TCRE_USE_XLCPP 1
    #endif  // TCRE_USE_XLCPP

    #ifndef TCRE_CLANG
        #define TCRE_CLANG 1
    #endif  // TCRE_CLANG

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __clang_version__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Clang 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

    #if defined(__GNUC__) && (4 <= __GNUC__)
        #define SYSTEM_ATTRIBUTE_UNUSED __attribute__((unused))
    #endif  // defined(__GNUC__) && (4 <= __GNUC__)

#endif  // defined(__ibmxl__)

#endif  // SYSTEM_HELPER_XLCPP_H
