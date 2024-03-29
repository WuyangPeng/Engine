///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:37)

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
