//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:16)

#ifndef SYSTEM_HELPER_LINUX_H
#define SYSTEM_HELPER_LINUX_H

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

    //  linux 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "linux"
    #define SYSTEM_PLATFORM_LINUX

    // 如果可用,确保我们有__GLIBC_PREREQ
    #include <cstdlib>

    // PC Linux 平台
    #if !defined(__LINUX__) && defined(__linux__)
        // 显然，许多 PC Linux 版本定义__linux__，但是我们使用__LINUX__
        // 为了避免破坏代码通过__LINUX__替换__linux__，我们只定义__LINUX__。
        #define __LINUX__
    #endif  // __LINUX__

    // 支持标准的整数类型。
    #include <inttypes.h>

    #define SYSTEM_LITTLE_ENDIAN

    #ifndef __GNUC__

        // 如果编译器不是gcc，我们仍然需要能够解析GNU系统头，其中一些（主要是<stdint.h>）使用GNU特定的扩展：

        #ifndef __extension__
            #define __extension__
        #endif  // __extension__

        #ifndef __const__
            #define __const__ const
        #endif  // __const__

        #ifndef __volatile__
            #define __volatile__ volatile
        #endif  // __volatile__

        #ifndef __signed__
            #define __signed__ signed
        #endif  // __signed__

        #ifndef __typeof__
            #define __typeof__ typeof
        #endif  // __typeof__

        #ifndef __inline__
            #define __inline__ inline
        #endif  // __inline__

    #endif  // __GNUC__

    #ifdef __ANDROID__
        #define SYSTEM_PLATFORM_ANDROID
    #endif  // __ANDROID__

#endif  // (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)

#endif  // SYSTEM_HELPER_LINUX_H
