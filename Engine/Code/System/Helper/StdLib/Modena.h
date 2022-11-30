///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 13:10)

#ifndef SYSTEM_HELPER_MODENA_H
#define SYSTEM_HELPER_MODENA_H

#if defined(MSIPL_COMPILE_H)

    //  Modena C++ 标准库（自带 KAI C++)

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION 1

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "Modena C++ 标准库"

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_MODENA static_cast<void>(0)

#endif  // MSIPL_COMPILE_H

#endif  // SYSTEM_HELPER_MODENA_H
