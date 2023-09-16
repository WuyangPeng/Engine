///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 17:50)

#ifndef SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
#define SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H

// 定义宏TCRE_CPPLIB_VERSION表示标准库版本，定义TCRE_SYSTEM_STDLIB表示标准库名称。

#include <cstddef>

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

    /// 这个必须放在第一个，
    /// 否则由于STLPort通常位于一些其他库的顶部，
    /// 我们可能最终检测到第一个而不是STLPort。
    #define TCRE_STDLIB_CONFIG "StdLib/STLPort.h"

#else  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

    /// 如果我们的std lib不是某个版本的STLPort，
    /// 并且没有被检测到，
    /// 那么包含<utility>，
    /// 因为它是包含真正的C++ std的最小的头文件。

    /// 一些std库不包含他们的C++相关的宏在<cstddef>，
    /// 所以这个额外的包含确保我们得到这些定义。
    /// 注意：不要依赖于包含这个头文件，
    /// 因为用户可以短路这个#include，
    /// 如果他们知道他们正在使用哪个std库。

    #if !defined(__LIBCOMO__) &&          \
        !defined(__STD_RWCOMPILER_H__) && \
        !defined(_RWSTD_VER) &&           \
        !defined(_LIBCPP_VERSION) &&      \
        !defined(__GLIBCPP__) &&          \
        !defined(__GLIBCXX__) &&          \
        !defined(__STL_CONFIG_H) &&       \
        !defined(__MSL_CPP__) &&          \
        !defined(__IBMCPP__) &&           \
        !defined(MSIPL_COMPILE_H) &&      \
        !defined(_YVALS) &&               \
        !defined(_CPPLIB_VER)

        #include <utility>

    #endif  // !defined(ALL_STDLIB)

    #if defined(__LIBCOMO__)

        // Comeau STL
        #define TCRE_STDLIB_CONFIG "StdLib/Libcomo.h"

    #elif defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)

        // Rogue Wave库
        #define TCRE_STDLIB_CONFIG "StdLib/Roguewave.h"

    #elif defined(_LIBCPP_VERSION)

        // libc++
        #define TCRE_STDLIB_CONFIG "StdLib/Libcpp.h"

    #elif defined(__GLIBCPP__) || defined(__GLIBCXX__)

        // GNU libstdc++ 3
        #define TCRE_STDLIB_CONFIG "StdLib/Libstdcpp3.h"

    #elif defined(__STL_CONFIG_H)

        // 通用 SGI STL
        #define TCRE_STDLIB_CONFIG "StdLib/Sgi.h"

    #elif defined(__MSL_CPP__)

        // MSL 标准库
        #define TCRE_STDLIB_CONFIG "StdLib/Msl.h"

    #elif defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

        // IBM z/OS XL C/C++
        #define TCRE_STDLIB_CONFIG "StdLib/XlcppZos.h"

    #elif defined(__IBMCPP__)

        // 采用默认的 VACPP std lib
        #define TCRE_STDLIB_CONFIG "StdLib/Vacpp.hpp"

    #elif defined(MSIPL_COMPILE_H)

        // Modena C++ 标准库
        #define TCRE_STDLIB_CONFIG "StdLib/Modena.h"

    #elif (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

        // Dinkumware 库（这必须出现在任何可能的替换库之后）
        #define TCRE_STDLIB_CONFIG "StdLib/Dinkumware.h"

    #else  // !defined(ALL_STDLIB)

        // 这必须是放在最后，生成一个错误，如果我们无法识别库
        #error "标准库无法被正确识别。"

    #endif  // defined(ALL_STDLIB)

#endif  // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#include TCRE_STDLIB_CONFIG

#endif  // SYSTEM_HELPER_SELECT_STDLIB_CONFIG_H
