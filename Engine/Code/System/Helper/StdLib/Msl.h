///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 10:09)

#ifndef SYSTEM_HELPER_MSL_H
#define SYSTEM_HELPER_MSL_H

#if defined(__MSL_CPP__)

    //  Metrowerks 标准库

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION __MSL_CPP__

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "Metrowerks 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_MSL static_cast<void>(0)

#endif  // __MSL_CPP__

#endif  // SYSTEM_HELPER_MSL_H
