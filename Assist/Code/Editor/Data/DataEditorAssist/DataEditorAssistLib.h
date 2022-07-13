///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/06 15:25)

#ifndef DATA_EDITOR_LIB_H
#define DATA_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATA_EDITOR_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DataEditorAssistD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataEditorAssist.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DATA_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "DataEditorAssistStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DataEditorAssistStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DATA_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATA_EDITOR_LIB_H
