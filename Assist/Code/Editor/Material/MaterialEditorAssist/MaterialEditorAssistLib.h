///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/08 15:24)

#ifndef MATERIAL_EDITOR_LIB_H
#define MATERIAL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MATERIAL_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MaterialEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MaterialEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MATERIAL_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MaterialEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MaterialEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MATERIAL_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MATERIAL_EDITOR_LIB_H
