//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:03)

#ifndef SYSTEM_HELPER_CODE_GEAR_H
#define SYSTEM_HELPER_CODE_GEAR_H

#ifdef __CODEGEARC__

    // CodeGear C++编译器设置：

    // 版本检查：最后已知的版本是0x621
    #if (0x621 < __CODEGEARC__)
        #error "未知版本"
    #endif  // 0x621 < __CODEGEARC__

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_CODE_GEAR
        #define TCRE_USE_CODE_GEAR 1
    #endif  // TCRE_USE_CODE_GEAR

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __CODEGEARC__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "CodeGear C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

    // 这些警告频繁发生在优化的模板代码中
    #pragma warn - 8004  // var赋值，但从未使用
    #pragma warn - 8008  // 条件总是真/假
    #pragma warn - 8066  // 死代码永远不会执行
    #pragma warn - 8104  // 静态成员构造函数不是线程安全
    #pragma warn - 8105  // 引用成员在没有构造函数的类中

    #if defined(NDEBUG)
        // 修复不合标准的<cstring>
        #include <cstring>
        #undef strcmp
    #endif  // defined(NDEBUG)

    // 修复不合标准的errno声明。
    #include <errno.h>
    #ifndef errno
        #define errno errno
    #endif  // errno

#endif  // __CODEGEARC__

#endif  // SYSTEM_HELPER_CODE_GEAR_H
