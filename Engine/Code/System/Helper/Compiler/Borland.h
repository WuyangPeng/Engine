/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：v0.0.0.1 (2025/08/14 16:44:58)

#ifndef SYSTEM_HELPER_BORLAND_H
#define SYSTEM_HELPER_BORLAND_H

/// Borland C++编译器设置：

#ifdef __BORLANDC__

    /// 版本检查：
    #if __BORLANDC__ < 0x540

        /// 我们不支持版本5.4之前的Borland：
        #error "编译器不支持配置——请重新配置"

    #elif (__BORLANDC__ == 0x600)

        #error "不再支持CBuilderX预览编译器"

    #endif  // __BORLANDC__

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_BORLANDC

        #define TCRE_USE_BORLANDC 1

    #endif  // TCRE_USE_BORLANDC

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __BORLANDC__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Borland C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

    #error "Borland C++ 当前版本尚不支持完整C++20，请换用其他编译器。"

#endif  // __BORLANDC__

#endif  // SYSTEM_HELPER_BORLAND_H
