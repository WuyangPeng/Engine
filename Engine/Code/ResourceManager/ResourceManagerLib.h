///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/10 13:52)

#ifndef SOUND_RESOURCE_MANAGER_LIB_H
#define SOUND_RESOURCE_MANAGER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RESOURCE_MANAGER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManager.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_RESOURCE_MANAGER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ResourceManagerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ResourceManagerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_RESOURCE_MANAGER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SOUND_RESOURCE_MANAGER_LIB_H