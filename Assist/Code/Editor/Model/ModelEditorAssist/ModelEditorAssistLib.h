///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/08 16:58)

#ifndef MODEL_EDITOR_LIB_H
#define MODEL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

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
