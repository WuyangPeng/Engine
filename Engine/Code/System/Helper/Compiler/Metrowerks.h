///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/18 23:29)

#ifndef SYSTEM_HELPER_METROWERKS_H
#define SYSTEM_HELPER_METROWERKS_H

#if defined(__MWERKS__)

    // Metrowerks C++ 编译器设置：

    #if __MWERKS__ < 0x2301

        #error "编译器未设置"

    #endif  // __MWERKS__ < 0x2301

    #if (0x3205 < __MWERKS__)

        #error "未知编译器"

    #endif  // (0x3205 < __MWERKS__)

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_METROWERKS

        #define TCRE_USE_METROWERKS 1

    #endif  // TCRE_USE_METROWERKS

    #if (__INTEL__ && _WIN32) || (__POWERPC__ && macintosh)

        #if __MWERKS__ == 0x3000

            #define TCRE_COMPILER_VERSION 8.0

        #elif __MWERKS__ == 0x3001

            #define TCRE_COMPILER_VERSION 8.1

        #elif __MWERKS__ == 0x3002

            #define TCRE_COMPILER_VERSION 8.2

        #elif __MWERKS__ == 0x3003

            #define TCRE_COMPILER_VERSION 8.3

        #elif __MWERKS__ == 0x3200

            #define TCRE_COMPILER_VERSION 9.0

        #elif __MWERKS__ == 0x3201

            #define TCRE_COMPILER_VERSION 9.1

        #elif __MWERKS__ == 0x3202

            #define TCRE_COMPILER_VERSION 9.2

        #elif __MWERKS__ == 0x3204

            #define TCRE_COMPILER_VERSION 9.3

        #elif __MWERKS__ == 0x3205

            #define TCRE_COMPILER_VERSION 9.4

        #elif __MWERKS__ == 0x3206

            #define TCRE_COMPILER_VERSION 9.5

        #elif __MWERKS__ == 0x3207

            #define TCRE_COMPILER_VERSION 9.6

        #else  // 0x3207 < __MWERKS__

            #define TCRE_COMPILER_VERSION __MWERKS__

        #endif  // __MWERKS__

    #else  // !(__INTEL__ && _WIN32) && !(__POWERPC__ && macintosh)

        #define TCRE_COMPILER_VERSION __MWERKS__

    #endif  // (__INTEL__ && _WIN32) || (__POWERPC__ && macintosh)

    #define TCRE_SYSTEM_COMPILER "Metrowerks CodeWarrior C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

#endif  // __MWERKS__

#endif  // SYSTEM_HELPER_METROWERKS_H
