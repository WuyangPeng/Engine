/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:49)

#ifndef PHYSICS_LIB_H
#define PHYSICS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PHYSICS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Physics.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_PHYSICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "PhysicsStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "PhysicsStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_PHYSICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PHYSICS_LIB_H