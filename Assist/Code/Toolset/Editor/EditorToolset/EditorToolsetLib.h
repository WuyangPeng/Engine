///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:43)

#ifndef EDITOR_TOOLSET_LIB_H
#define EDITOR_TOOLSET_LIB_H

#include "Helper/Helper.h"

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
