///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 11:24)

#ifndef SYSTEM_HELPER_HP_ACC_H
#define SYSTEM_HELPER_HP_ACC_H

// HP aCC C++ 编译器设置：

#ifdef __HP_aCC

    // 版本检查：我们不支持版本33000之前的HP aCC：
    #if __HP_aCC < 33000

        #error "编译器不被支持"

    #endif  // __HP_aCC < 33000

    // 在PA-RISC上支持aCC的扩展检查
    #if 30000 < __HP_aCC && __HP_aCC < 50000

        #if __HP_aCC < 38000

            // 不支持版本A.03.80之前的版本
            #error "编译器不被支持"

        #elif !defined(__hpxstd98)

            // 必须使用选项+hpxstd98和比A.03.80更高版本进行编译
            #error "编译器选项“+hpxstd98”是正确支持所必需的"

        #endif  // PA-RISC

    #endif  // 30000 < __HP_aCC && __HP_aCC < 50000

    // HP-UX/ia64的最后已的版本为61300，PA-RISC的最后已的版本为38000
    #if ((61300 < __HP_aCC) || ((38000 < __HP_aCC) && defined(__hpxstd98)))

        #error "未知编译器版本"

    #endif  // ((61300 < __HP_aCC) || ((38000 < __HP_aCC) && defined(__hpxstd98)))

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_HP_ACC

        #define TCRE_USE_HP_ACC 1

    #endif  // TCRE_USE_HP_ACC

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __HP_aCC

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "HP aCC 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __HP_aCC

#endif  // SYSTEM_HELPER_HP_ACC_H
