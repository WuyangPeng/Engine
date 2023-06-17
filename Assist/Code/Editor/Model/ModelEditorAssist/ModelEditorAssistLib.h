///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/15 15:20)

#ifndef MODEL_EDITOR_LIB_H
#define MODEL_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MODEL_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ModelEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ModelEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_MODEL_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ModelEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ModelEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_MODEL_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MODEL_EDITOR_LIB_H
