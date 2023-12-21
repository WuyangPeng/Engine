/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:45)

#ifndef WORLD_SERVER_CORE_LIB_H
#define WORLD_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

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