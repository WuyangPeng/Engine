///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 11:24)

#ifndef SYSTEM_HELPER_VISUALC_H
#define SYSTEM_HELPER_VISUALC_H

#ifdef _MSC_VER

    /// Microsoft Visual C++ 编译器设置：

    /// 我们需要小心这个文件中的检查，
    /// 因为与通常的理论相反，
    /// 存在具有_MSC_VER的最终数字非零的版本（主要是MIPS交叉编译器）。

    /// 所以我们测试XXXX <= _MSC_VER或者_MSC_VER < XXXX，
    /// 没有其他比较是安全的。

    /// 版本检查：我们不支持版本7.1之前的Visual C++：
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

    #else  // 1915 <= _MSC_VER

        #define SYSTEM_CPP_STANDARD 17

    #endif  // _MSC_FULL_VER < 180020827

    #ifndef MSVC_COMPILER_VERSION

        #if defined(UNDER_CE)

            #if _MSC_VER < 1400

                // 注意：我不知道任何CE编译器13xx版本
                #error "未知的EVC++编译器版本"

            #elif _MSC_VER < 1500

                #define MSVC_COMPILER_VERSION evc8
                #define SYSTEM_USING_VC80 static_cast<void>(0)

            #elif _MSC_VER < 1600

                #define MSVC_COMPILER_VERSION evc9
                #define SYSTEM_USING_VC90 static_cast<void>(0)

            #elif _MSC_VER < 1700

                #define MSVC_COMPILER_VERSION evc10
                #define SYSTEM_USING_VC100 static_cast<void>(0)

            #elif _MSC_VER < 1800

                #define MSVC_COMPILER_VERSION evc11
                #define SYSTEM_USING_VC110 static_cast<void>(0)

            #elif _MSC_VER < 1900

                #define MSVC_COMPILER_VERSION evc12
                #define SYSTEM_USING_VC120 static_cast<void>(0)

            #elif _MSC_VER < 2000

                #define MSVC_COMPILER_VERSION evc14
                #define SYSTEM_USING_VC140 static_cast<void>(0)

            #else  // 2000 <= _MSC_VER

                #error "未知的 EVC++ 编译器版本"

            #endif  // _MSC_VER

        #else  // !defined(UNDER_CE)

            /// 微软的Visual Studio版本：
            /// MSVC 6是版本12.00
            /// MSVC 7.0是版本13.00（MSVS 2002）
            /// MSVC 7.1是版本13.10（MSVS 2003）
            /// MSVC 8.0是版本14.00（MSVS 2005）
            /// MSVC 9.0是版本15.00（MSVS 2008）
            /// MSVC 10.0是版本16.00（MSVS 2010）
            /// MSVC 11.0是版本17.00（MSVS 2012）
            /// MSVC 12.0是版本18.00（MSVS 2013）
            /// MSVC 14.0是版本19.00（MSVS 2015）
            /// MSVC 14.1是版本19.10（MSVS 2017）
            /// MSVC 14.2是版本19.20（MSVS 2019）
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
                #define SYSTEM_USING_VC80 static_cast<void>(0)

            #elif _MSC_VER < 1600

                #define MSVC_COMPILER_VERSION 9.0
                #define SYSTEM_USING_VC90 static_cast<void>(0)

            #elif _MSC_VER < 1700

                #define MSVC_COMPILER_VERSION 10.0
                #define SYSTEM_USING_VC100 static_cast<void>(0)

            #elif _MSC_VER < 1800

                #define MSVC_COMPILER_VERSION 11.0
                #define SYSTEM_USING_VC110 static_cast<void>(0)

            #elif _MSC_VER < 1900

                #define MSVC_COMPILER_VERSION 12.0
                #define SYSTEM_USING_VC120 static_cast<void>(0)

            #elif _MSC_VER < 1910

                #define MSVC_COMPILER_VERSION 14.0
                #define SYSTEM_USING_VC140 static_cast<void>(0)

            #elif _MSC_VER < 1920

                #define MSVC_COMPILER_VERSION 14.1
                #define SYSTEM_USING_VC141 static_cast<void>(0)

            #elif _MSC_VER < 1930

                #define MSVC_COMPILER_VERSION 14.2
                #define SYSTEM_USING_VC142 static_cast<void>(0)

            #else  // 2000 <= _MSC_VER

                #define MSVC_COMPILER_VERSION _MSC_VER

            #endif  // _MSC_VER

        #endif  // defined(UNDER_CE)

    #endif  // MSVC_COMPILER_VERSION

    #if SYSTEM_CPP_STANDARD < 14

        #define SYSTEM_DEPRECATED(x) __declspec(deprecated)

    #endif  // SYSTEM_CPP_STANDARD < 14

    #if 1600 <= _MSC_VER

        #include <cstdint>

    #else  // _MSC_VER < 1600

        #error "不支持低版本的Visual Studio。"

    #endif  // 1600 <= _MSC_VER

#endif  // _MSC_VER

#endif  // SYSTEM_HELPER_VISUALC_H
