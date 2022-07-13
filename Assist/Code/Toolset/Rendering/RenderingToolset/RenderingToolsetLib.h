///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 14:03)

#ifndef RENDERING_TOOLSET_LIB_H
#define RENDERING_TOOLSET_LIB_H

#include "Rendering/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RENDERING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RenderingToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RenderingToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_RENDERING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RenderingToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RenderingToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_RENDERING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RENDERING_TOOLSET_LIB_H
