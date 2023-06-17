///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/12 16:43)

#ifndef PHYSICS_EXAMPLE_LIB_H
#define PHYSICS_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PHYSICS_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "PhysicsExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_PHYSICS_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "PhysicsExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_PHYSICS_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PHYSICS_EXAMPLE_LIB_H
