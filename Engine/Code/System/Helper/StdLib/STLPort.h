///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 17:55)

#ifndef SYSTEM_HELPER_STL_PORT_H
#define SYSTEM_HELPER_STL_PORT_H

#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

    //  STLPort 标准库配置

    #ifndef TCRE_CPPLIB_VERSION
        #define TCRE_CPPLIB_VERSION __SGI_STL_PORT
    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB
        #define TCRE_SYSTEM_STDLIB "STLPort 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
    #endif  // !TCRE_STDLIB

    #if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
        #include <cstddef>
        #if !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
            #error "这不是STLPort!"
        #endif  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)
    #endif  // !defined(__SGI_STL_PORT) && !defined(_STLPORT_VERSION)

    #if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))
        #include <unistd.h>
    #endif  // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

    #define TCRE_USE_STLPORT static_cast<void>(0)

#endif  // defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)

#endif  // SYSTEM_HELPER_STL_PORT_H
