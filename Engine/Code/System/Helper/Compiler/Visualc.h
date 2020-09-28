//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:10)

#ifndef SYSTEM_HELPER_VISUALC_H
#define SYSTEM_HELPER_VISUALC_H

#ifdef _MSC_VER

    // Microsoft Visual C++ 编译器设置：

    // 我们需要小心这个文件中的检查，因为与通常的理论相反，存在具有_MSC_VER的最终数字非零的版本（主要是MIPS交叉编译器）。

    // 所以我们测试XXXX <= _MSC_VER或者_MSC_VER < XXXX。没有其他比较是安全的。

    // 版本检查：我们不支持版本7.1之前的Visual C++：
    #if _MSC_VER < 1310
        #error "编译器未配置"
    #endif  // _MSC_VER < 1310

    #ifndef MSVC_VERSION
        #define MSVC_VERSION _MSC_VER
    #endif  // MSVC_VERSION

    #ifndef TCRE_USE_MSVC
        #define TCRE_USE_MSVC MSVC_VERSION
    #endif  // TCRE_USE_MSVC

    #ifndef MSVC_FULL_VERSION

        #if 100000000 < _MSC_FULL_VER
            #define MSVC_FULL_VERSION _MSC_FULL_VER
        #else  // _MSC_FULL_VER <= 100000000
            #define MSVC_FULL_VERSION (_MSC_FULL_VER * 10)
        #endif  // 100000000 < _MSC_FULL_VER

    #endif  // MSVC_FULL_VERSION

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION MSVC_VERSION
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Microsoft Visual C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

    #if _MSC_FULL_VER < 180020827
        #define SYSTEM_CPP_STANDARD 3
    #elif _MSC_FULL_VER < 190023026
        #define SYSTEM_CPP_STANDARD 11
    #elif _MSC_VER < 1915
        #define SYSTEM_CPP_STANDARD 14
    #else
        #define SYSTEM_CPP_STANDARD 17
    #endif  // _MSC_FULL_VER < 180020827

    #ifndef MSVC_COMPILER_VERSION

        #if defined(UNDER_CE)
            #if _MSC_VER < 1400

                // 注意：我不知道任何CE编译器13xx版本
                #error "未知的EVC++编译器版本"

            #elif _MSC_VER < 1500
                #define MSVC_COMPILER_VERSION evc8
                #define SYSTEM_USING_VC80
            #elif _MSC_VER < 1600
                #define MSVC_COMPILER_VERSION evc9
                #define SYSTEM_USING_VC90
            #elif _MSC_VER < 1700
                #define MSVC_COMPILER_VERSION evc10
                #define SYSTEM_USING_VC100
            #elif _MSC_VER < 1800
                #define MSVC_COMPILER_VERSION evc11
                #define SYSTEM_USING_VC110
            #elif _MSC_VER < 1900
                #define MSVC_COMPILER_VERSION evc12
                #define SYSTEM_USING_VC120
            #elif _MSC_VER < 2000
                #define MSVC_COMPILER_VERSION evc14
                #define SYSTEM_USING_VC140
            #else  // 2000 <= _MSC_VER
                #error "未知的 EVC++ 编译器版本"
            #endif  // _MSC_VER

        #else  // !defined(UNDER_CE)                  \
            // 微软的Visual Studio版本：        \
            // MSVC 6是版本12.00                   \
            // MSVC 7.0是版本13.00（MSVS 2002）  \
            // MSVC 7.1是版本13.10（MSVS 2003）  \
            // MSVC 8.0是版本14.00（MSVS 2005）  \
            // MSVC 9.0是版本15.00（MSVS 2008）  \
            // MSVC 10.0是版本16.00（MSVS 2010） \
            // MSVC 11.0是版本17.00（MSVS 2012） \
            // MSVC 12.0是版本18.00（MSVS 2013） \
            // MSVC 14.0是版本19.00（MSVS 2015） \
            // MSVC 14.1是版本19.10（MSVS 2017）
            #if _MSC_VER < 1310
                // 注意：不支持7.0以下的版本。
                #define MSVC_COMPILER_VERSION 5.0
            #elif _MSC_VER < 1300
                #define MSVC_COMPILER_VERSION 6.0
            #elif _MSC_VER < 1310
                #define MSVC_COMPILER_VERSION 7.0
            #elif _MSC_VER < 1400
                #define MSVC_COMPILER_VERSION 7.1
            #elif _MSC_VER < 1500
                #define MSVC_COMPILER_VERSION 8.0
                #define SYSTEM_USING_VC80
            #elif _MSC_VER < 1600
                #define MSVC_COMPILER_VERSION 9.0
                #define SYSTEM_USING_VC90
            #elif _MSC_VER < 1700
                #define MSVC_COMPILER_VERSION 10.0
                #define SYSTEM_USING_VC100
            #elif _MSC_VER < 1800
                #define MSVC_COMPILER_VERSION 11.0
                #define SYSTEM_USING_VC110
            #elif _MSC_VER < 1900
                #define MSVC_COMPILER_VERSION 12.0
                #define SYSTEM_USING_VC120
            #elif _MSC_VER < 1910
                #define MSVC_COMPILER_VERSION 14.0
                #define SYSTEM_USING_VC140                
            #elif _MSC_VER < 1920
                #define MSVC_COMPILER_VERSION 14.1
                #define SYSTEM_USING_VC141
            #elif _MSC_VER < 1930
                #define BOOST_COMPILER_VERSION 14.2
                #define SYSTEM_USING_VC142
            #else  // 2000 <= _MSC_VER
                #define MSVC_COMPILER_VERSION _MSC_VER
            #endif  // _MSC_VER
        #endif  // defined(UNDER_CE)

    #endif  // MSVC_COMPILER_VERSION

    #if 1600 <= _MSC_VER
        #include <cstdint>
    #else  // _MSC_VER < 1600

        typedef __int8 int8_t;
        typedef __int16 int16_t;
        typedef __int32 int32_t;
        typedef __int64 int64_t;
        typedef unsigned __int8 uint8_t;
        typedef unsigned __int16 uint16_t;
        typedef unsigned __int32 uint32_t;
        typedef unsigned __int64 uint64_t;

        #define INT8_MIN _I8_MIN
        #define INT8_MAX _I8_MAX
        #define INT16_MIN _I16_MIN
        #define INT16_MAX _I16_MAX
        #define INT32_MIN _I32_MIN
        #define INT32_MAX _I32_MAX
        #define INT64_MIN _I64_MIN
        #define INT64_MAX _I64_MAX
        #define UINT8_MAX _UI8_MAX
        #define UINT16_MAX _UI16_MAX
        #define UINT32_MAX _UI32_MAX
        #define UINT64_MAX _UI64_MAX
    #endif  // 1600 <= _MSC_VER

#endif  // _MSC_VER

#endif  // SYSTEM_HELPER_VISUALC_H
