///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 16:11)

#ifndef PHYSICS_EXAMPLE_LIB_H
#define PHYSICS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

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
