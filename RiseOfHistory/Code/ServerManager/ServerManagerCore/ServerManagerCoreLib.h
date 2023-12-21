/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef SERVER_MANAGER_CORE_LIB_H
#define SERVER_MANAGER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SERVER_MANAGER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SERVER_MANAGER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SERVER_MANAGER_CORE_LIB_H