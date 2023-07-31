///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:34)

#ifndef RESOURCE_MANAGER_TOOLSET_LIB_H
#define RESOURCE_MANAGER_TOOLSET_LIB_H

#include "ResourceManager/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RESOURCE_MANAGER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManagerToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_RESOURCE_MANAGER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManagerToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_RESOURCE_MANAGER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RESOURCE_MANAGER_TOOLSET_LIB_H
