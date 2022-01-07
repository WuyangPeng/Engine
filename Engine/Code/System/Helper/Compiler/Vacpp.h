///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:43)

#ifndef SYSTEM_HELPER_VACPP_H
#define SYSTEM_HELPER_VACPP_H

#if defined(__IBMCPP__)

    // Visual Age (IBM) C++ 编译器设置：

    #if __IBMCPP__ < 500
        #error "编译器未配置"
    #endif  // __IBMCPP__ < 500

    #if (1210 < __IBMCPP__)
        #error "未知编译器"
    #endif  // (1210 < __IBMCPP__)

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_VACPP
        #define TCRE_USE_VACPP 1
    #endif  // TCRE_USE_VACPP

    #ifndef COMPILER_VERSION
        #define COMPILER_VERSION __IBMCPP__
    #endif  // COMPILER_VERSION

    #ifndef SYSTEM_COMPILER
        #define SYSTEM_COMPILER "IBM Visual Age 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // SYSTEM_COMPILER

#endif  // defined(__IBMCPP__)

#endif  // SYSTEM_HELPER_VACPP_H
