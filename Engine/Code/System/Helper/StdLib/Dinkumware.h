//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:18)

#ifndef SYSTEM_HELPER_DINKUMWARE_H
#define SYSTEM_HELPER_DINKUMWARE_H

#if (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

    //  Dinkumware 标准库配置：

    #ifdef _CPPLIB_VER
        #define TCRE_DINKUMWARE_STDLIB _CPPLIB_VER
    #else  // !_CPPLIB_VER
        #define TCRE_DINKUMWARE_STDLIB 1
    #endif  // _CPPLIB_VER

    #ifndef TCRE_CPPLIB_VERSION
        #define TCRE_CPPLIB_VERSION TCRE_DINKUMWARE_STDLIB
    #endif  // TCRE_CPPLIB_VERSION

    #ifdef _CPPLIB_VER
        #define TCRE_SYSTEM_STDLIB "Dinkumware 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)
    #else  // !_CPPLIB_VER
        #define TCRE_SYSTEM_STDLIB "Dinkumware 标准库版本 1.x"
    #endif  // _CPPLIB_VER

    #define TCRE_USE_DINKUMWARE

#endif  // (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)

#endif  // SYSTEM_HELPER_DINKUMWARE_H
