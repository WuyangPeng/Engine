///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:28)

#ifndef MATERIAL_EDITOR_LIB_H
#define MATERIAL_EDITOR_LIB_H

#include "Helper/UserMacro.h"

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
