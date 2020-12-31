//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:19)

#ifndef SYSTEM_HELPER_VACPP_H
#define SYSTEM_HELPER_VACPP_H

#if defined(__IBMCPP__)

    #ifndef TCRE_CPPLIB_VERSION
        #define TCRE_CPPLIB_VERSION 1
    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB
        #define TCRE_SYSTEM_STDLIB "Visual Age 默认 标准库版本 "
    #endif  // !TCRE_STDLIB

    #if !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))
        #include <unistd.h>
    #endif  // !defined(CYGWIN) && (defined(__unix__) || defined(__unix) || defined(unix) || defined(__APPLE__) || defined(__APPLE) || defined(APPLE))

    #define TCRE_USE_VACPP

#endif  // __IBMCPP__

#endif  // SYSTEM_HELPER_VACPP_H
