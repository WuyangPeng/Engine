///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 11:23)

#ifndef SYSTEM_HELPER_COMPAQ_CXX_H
#define SYSTEM_HELPER_COMPAQ_CXX_H

#ifdef __DECCXX

    // Tru64 C++ 编译器设置（现为 HP）：

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_COMPAQ_CXX

        #define TCRE_USE_COMPAQ_CXX 1

    #endif  // TCRE_USE_COMPAQ_CXX

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __DECCXX_VER

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "HP Tru64 C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __DECCXX

#endif  // SYSTEM_HELPER_COMPAQ_CXX_H
