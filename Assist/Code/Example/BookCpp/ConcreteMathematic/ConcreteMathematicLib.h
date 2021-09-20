///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef CONCRETE_MATHEMATIC_LIB_H
#define CONCRETE_MATHEMATIC_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CONCRETE_MATHEMATIC_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ConcreteMathematicD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ConcreteMathematic.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CONCRETE_MATHEMATIC_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ConcreteMathematicStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ConcreteMathematicStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CONCRETE_MATHEMATIC_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CONCRETE_MATHEMATIC_LIB_H
