///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:31)

#ifndef CHAT_LIB_H
#define CHAT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CHAT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ChatD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Chat.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CHAT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ChatStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ChatStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CHAT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CHAT_LIB_H
