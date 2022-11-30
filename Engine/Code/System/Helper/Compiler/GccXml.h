///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/18 23:29)

#ifndef SYSTEM_HELPER_GCC_XML_H
#define SYSTEM_HELPER_GCC_XML_H

#ifdef __GCCXML__

    // GCC-XML C++ 编译器设置：

    #ifndef SYSTEM_CPP_STANDARD

        #define SYSTEM_CPP_STANDARD 3

    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_GCC_XML

        #define TCRE_USE_GCC_XML 1

    #endif  // TCRE_USE_GCC_XML

    #ifndef TCRE_COMPILER_VERSION

        #define TCRE_COMPILER_VERSION __GCCXML__

    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "GCC-XML C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)

    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __GCCXML__

#endif  // SYSTEM_HELPER_GCC_XML_H
