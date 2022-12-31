///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/16 22:12)

#ifndef SYSTEM_HELPER_XLCPP_ZOS_H
#define SYSTEM_HELPER_XLCPP_ZOS_H

#if defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    // IBM z/OS XL C/C++ 编译器设置：

    // 当前支持的最旧的编译器版本是2.1（V2R1）
    #if !defined(__IBMCPP__) || !defined(__COMPILER_VER__) || __COMPILER_VER__ < 0x42010000

        #error "不支持或未配置的编译器"

    #endif  // !defined(__IBMCPP__) || !defined(__COMPILER_VER__) || __COMPILER_VER__ < 0x42010000

    #if (0x42010000 < __COMPILER_VER__)

        #error "未知编译器"

    #endif  // (0x42010000 < __COMPILER_VER__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_XLCPP_ZOS

        #define TCRE_USE_XLCPP_ZOS 1

    #endif  // TCRE_USE_XLCPP_ZOS

    #ifndef COMPILER_VERSION

        #define COMPILER_VERSION __COMPILER_VER__

    #endif  // COMPILER_VERSION

    #ifndef SYSTEM_COMPILER

        #define SYSTEM_COMPILER "IBM z/OS XL C/C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // SYSTEM_COMPILER

    // 对 __UU, __C99, __TR1, ...
    #include <features.h>

extern "builtin" long __builtin_expect(long, long);

    #define TCRE_LIKELY(x) __builtin_expect((x) && true, 1)
    #define TCRE_UNLIKELY(x) __builtin_expect((x) && true, 0)

#endif  // defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

#endif  // SYSTEM_HELPER_XLCPP_ZOS_H
