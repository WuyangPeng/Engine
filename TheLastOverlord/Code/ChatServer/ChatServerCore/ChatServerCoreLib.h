///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 20:57)

#ifndef CHAT_SERVER_CORE_LIB_H
#define CHAT_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(_MSC_VER)

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

#endif  // _MSC_VER

#endif  // CHAT_SERVER_CORE_LIB_H