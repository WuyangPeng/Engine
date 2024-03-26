/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_MSL_H
#define SYSTEM_HELPER_MSL_H

#if defined(__MSL_CPP__)

    ///  Metrowerks 标准库

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION __MSL_CPP__

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "Metrowerks 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_MSL static_cast<void>(0)

#endif  // __MSL_CPP__

#endif  // SYSTEM_HELPER_MSL_H
