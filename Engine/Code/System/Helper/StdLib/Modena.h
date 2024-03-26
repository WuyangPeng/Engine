/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_MODENA_H
#define SYSTEM_HELPER_MODENA_H

#if defined(MSIPL_COMPILE_H)

    ///  Modena C++ 标准库（自带 KAI C++)

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION 1

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "Modena C++ 标准库"

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_MODENA static_cast<void>(0)

#endif  // MSIPL_COMPILE_H

#endif  // SYSTEM_HELPER_MODENA_H
