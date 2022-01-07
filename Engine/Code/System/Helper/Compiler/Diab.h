///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:42)

#ifndef SYSTEM_HELPER_DIAB_H
#define SYSTEM_HELPER_DIAB_H

#ifdef __DCC__

    // Wind River Diab C++编译器设置：

    #ifndef __EDG_VERSION__
        #error "未知的Diab编译器版本"
    #endif  // __EDG_VERSION__

    #ifndef TCRE_USE_DCC
        #define TCRE_USE_DCC 1
    #endif  // TCRE_USE_DCC

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __EDG_VERSION__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Wind River Diab C++ 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __DCC__

#endif  // SYSTEM_HELPER_DIAB_H
