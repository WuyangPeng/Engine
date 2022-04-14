///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/27 13:42)

#ifndef RENDERING_LIB_H
#define RENDERING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RENDERING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RenderingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Rendering.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_RENDERING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RenderingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RenderingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_RENDERING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RENDERING_LIB_H