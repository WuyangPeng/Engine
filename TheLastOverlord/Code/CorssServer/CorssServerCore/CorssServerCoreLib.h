/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_CORE_LIB_H
#define CORSS_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORSS_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CorssServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CorssServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CORSS_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CorssServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CorssServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CORSS_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORSS_SERVER_CORE_LIB_H