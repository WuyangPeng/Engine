/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 17:28)

#ifndef SYSTEM_HELPER_VA_CPP_H
#define SYSTEM_HELPER_VA_CPP_H

#if defined(__IBMCPP__)

    /// Visual Age (IBM) C++ 编译器设置：

    #if __IBMCPP__ < 500

        #error "编译器未配置"

    #endif  // __IBMCPP__ < 500

    #if (1210 < __IBMCPP__)

        #error "未知编译器"

    #endif  // (1210 < __IBMCPP__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_VA_CPP

        #define TCRE_USE_VA_CPP 1

    #endif  // TCRE_USE_VA_CPP

    #ifndef COMPILER_VERSION

        #define COMPILER_VERSION __IBMCPP__

    #endif  // COMPILER_VERSION

    #ifndef SYSTEM_COMPILER

        #define SYSTEM_COMPILER "IBM Visual Age 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // SYSTEM_COMPILER

#endif  // defined(__IBMCPP__)

#endif  // SYSTEM_HELPER_VA_CPP_H
