/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:26)

#ifndef CHAT_SERVER_CORE_LIB_H
#define CHAT_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CHAT_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ChatServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ChatServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CHAT_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ChatServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ChatServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CHAT_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CHAT_SERVER_CORE_LIB_H