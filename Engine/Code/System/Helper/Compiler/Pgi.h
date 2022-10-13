///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:13)

#ifndef SYSTEM_HELPER_PGI_H
#define SYSTEM_HELPER_PGI_H

#if defined(__PGI)

    //  PGI C++ 编译器设置：

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_PGI

        #define TCRE_USE_PGI 1

    #endif  // TCRE_USE_PGI

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION SYSTEM_CONCATENATOR(_PGIC__, __PGIC_MINOR__)

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "PGI 编译器版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

    // PGI主要与GNU兼容。 所以从那开始。
    #include "Gcc.h"

#endif  // defined(__PGI)

#endif  // SYSTEM_HELPER_PGI_H
