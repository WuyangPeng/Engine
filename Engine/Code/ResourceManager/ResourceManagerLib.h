///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 14:32)

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