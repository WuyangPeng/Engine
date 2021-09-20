///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/24 15:20)

#ifndef CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_LIB_H
#define CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppEffectiveObjectOrientedSoftwareConstructionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppEffectiveObjectOrientedSoftwareConstruction.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppEffectiveObjectOrientedSoftwareConstructionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppEffectiveObjectOrientedSoftwareConstructionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_EFFECTIVE_OBJECT_ORIENTED_SOFTWARE_CONSTRUCTION_LIB_H
