///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:15)

#ifndef USER_INTERFACE_EDITOR_LIB_H
#define USER_INTERFACE_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "UserInterfaceEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "UserInterfaceEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_USER_INTERFACE_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "UserInterfaceEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "UserInterfaceEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_USER_INTERFACE_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USER_INTERFACE_EDITOR_LIB_H
