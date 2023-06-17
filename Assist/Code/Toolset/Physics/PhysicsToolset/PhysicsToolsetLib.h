///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 16:40)

#ifndef PHYSICS_TOOLSET_LIB_H
#define PHYSICS_TOOLSET_LIB_H

#include "Physics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PHYSICS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "PhysicsToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_PHYSICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "PhysicsToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_PHYSICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PHYSICS_TOOLSET_LIB_H
