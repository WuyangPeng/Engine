//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 10:22)

#ifndef SYSTEM_HELPER_BORLAND_H
#define SYSTEM_HELPER_BORLAND_H

// Borland C++编译器设置：

#ifdef __BORLANDC__

    // 版本检查：
    #if __BORLANDC__ < 0x540

        // 我们不支持版本5.4之前的Borland：
        #error "编译器不支持配置——请重新配置"

    #elif (0x613 < __BORLANDC__)

        // 所知的最后的编译器版本：
        #error "未知的编译器版本"

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

    // 支持宏以帮助标准库检测
    #if (__BORLANDC__ < 0x560) || defined(_USE_OLD_RW_STL)
        #define TCRE_BCB_WITH_ROGUE_WAVE
    #elif __BORLANDC__ < 0x570
        #define TCRE_BCB_WITH_STLPORT
    #else  // 0x570 <= __BORLANDC__
        #define TCRE_BCB_WITH_DINKUMWARE
    #endif  // __BORLANDC__

    // 版本5.51及以下：
    #if (__BORLANDC__ <= 0x551)

        // 缺少WCHAR_MAX/WCHAR_MIN的解决方法
        #include <climits>
        #include <cwchar>

        #ifndef WCHAR_MAX
            #define WCHAR_MAX 0xFFFF
        #endif  // WCHAR_MAX

        #ifndef WCHAR_MIN
            #define WCHAR_MIN 0
        #endif  // WCHAR_MIN

    #endif  // (__BORLANDC__ <= 0x551)

    // Borland C ++ Builder 6及以下版本：
    #if (__BORLANDC__ <= 0x564)

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

    #endif  // (__BORLANDC__ <= 0x564)

    // Borland C ++ Builder 2006 Update 2及更高版本：
    #if (__BORLANDC__ <= 0x582)

        #ifdef defined(linux) || defined(__linux__) || defined(__linux)
            // _CPPUNWIND由于某种原因未自动设置
            #pragma defineonoption CPPUNWIND - x
        #endif  // defined(linux) || defined(__linux__) || defined(__linux)

    #endif  // (__BORLANDC__ <= 0x582)

    // Borland C++ Builder 6默认使用STLPort。
    // 如果定义_USE_OLD_RW_STL，那么我们对Rogue Wave实现具有0x560或更高版本，这可能有std::DBL_MAX错误。
    #if defined(TCRE_BCB_WITH_ROGUE_WAVE)

        // <climits>部分不合标准，一些宏定义了真正在命名空间std中的符号，
        // 所以你最终不得不使用std::DBL_MAX这样的非法构造，作为一个修复，我们只需要包含float.h。
        #include <float.h>

    #endif  // defined(TCRE_BCB_WITH_ROGUE_WAVE)

#endif  // __BORLANDC__

#endif  // SYSTEM_HELPER_BORLAND_H
