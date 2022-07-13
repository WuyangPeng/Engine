///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 14:44)

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
