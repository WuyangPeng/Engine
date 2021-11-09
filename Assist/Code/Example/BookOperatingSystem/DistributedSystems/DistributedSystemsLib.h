///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#ifndef DISTRIBUTED_SYSTEMS_LIB_H
#define DISTRIBUTED_SYSTEMS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DISTRIBUTED_SYSTEMS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DistributedSystemsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DistributedSystems.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DISTRIBUTED_SYSTEMS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "DistributedSystemsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DistributedSystemsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DISTRIBUTED_SYSTEMS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DISTRIBUTED_SYSTEMS_LIB_H
