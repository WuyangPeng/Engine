///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:14)

#ifndef USER_INTERFACE_TOOLSET_LIB_H
#define USER_INTERFACE_TOOLSET_LIB_H

#include "UserInterface/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USER_INTERFACE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "UserInterfaceToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "UserInterfaceToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_USER_INTERFACE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "UserInterfaceToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "UserInterfaceToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_USER_INTERFACE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USER_INTERFACE_TOOLSET_LIB_H
