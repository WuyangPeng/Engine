///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:34)

#ifndef EDITOR_TOOLSET_LIB_H
#define EDITOR_TOOLSET_LIB_H

#include "Macro/Macro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EditorToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EditorToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "EditorToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EditorToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EDITOR_TOOLSET_LIB_H
