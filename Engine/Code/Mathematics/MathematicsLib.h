///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:18)

#ifndef MATHEMATICS_LIB_H
#define MATHEMATICS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MATHEMATICS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MathematicsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Mathematics.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MATHEMATICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MathematicsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MathematicsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MATHEMATICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MATHEMATICS_LIB_H