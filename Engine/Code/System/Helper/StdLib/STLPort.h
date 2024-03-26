/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_STL_PORT_H
#define SYSTEM_HELPER_STL_PORT_H

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

    ///  STLPort 标准库配置

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION __SGI_STL_PORT

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "STLPort 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

        #include <cstddef>

        #if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

            #error "这不是STLPort!"

        #endif  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

    #endif  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

    #if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

        #include <unistd.h>

    #endif  // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

    #define TCRE_USE_STL_PORT static_cast<void>(0)

#endif  // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#endif  // SYSTEM_HELPER_STL_PORT_H
