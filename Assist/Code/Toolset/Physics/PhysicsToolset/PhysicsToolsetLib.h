///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:58)

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
