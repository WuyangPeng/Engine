/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:13)

#ifndef SYSTEM_HELPER_DIGITAL_MARS_H
#define SYSTEM_HELPER_DIGITAL_MARS_H

#if defined(__DMC__)

    // Digital Mars C++ 编译器设置：

    #if (__DMC__ <= 0x840)

        #error "编译器未配置"

    #endif  // __DMC__ <= 0x840

    // 最后已知的版本是：
    #if (0x848 < __DMC__)

        #error "未知编译器未配置"

    #endif  // 0x848 < __DMC__

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_DIGITAL_MARS

        #define TCRE_USE_DIGITAL_MARS 1

    #endif  // TCRE_USE_DIGITAL_MARS

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __DMC__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER __DMC_VERSION_STRING__

    #endif  // TCRE_SYSTEM_COMPILER

    #include <cstddef>

#endif  // __DMC__

#endif  // SYSTEM_HELPER_DIGITAL_MARS_H
