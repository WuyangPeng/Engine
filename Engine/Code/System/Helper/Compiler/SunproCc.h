///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:15)

#ifndef SYSTEM_HELPER_SUNPRO_CC_H
#define SYSTEM_HELPER_SUNPRO_CC_H

#if defined(__SUNPRO_CC)

    // Sun C++ 编译器设置：

    #if __SUNPRO_CC < 0x400

        #error "编译器未配置"

    #endif  // __SUNPRO_CC < 0x400

    #if (0x5150 < __SUNPRO_CC)

        #error "未知的编译器"

    #endif  // (0x5150 < __SUNPRO_CC)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_SUNPRO_CC

        #define TCRE_USE_SUNPRO_CC 1

    #endif  // TCRE_USE_SUNPRO_CC

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __SUNPRO_CC

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "Sun 编译器版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // defined(__SUNPRO_CC)

#endif  // SYSTEM_HELPER_SUNPRO_CC_H
