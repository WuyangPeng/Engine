///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 18:13)

#ifndef WORLD_SERVER_CORE_LIB_H
#define WORLD_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_WORLD_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "WorldServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "WorldServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_WORLD_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "WorldServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "WorldServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_WORLD_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // WORLD_SERVER_CORE_LIB_H
