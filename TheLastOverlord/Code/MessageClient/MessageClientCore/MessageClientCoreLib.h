///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 21:03)

#ifndef MESSAGE_CLIENT_CORE_LIB_H
#define MESSAGE_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MESSAGE_CLIENT_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MessageClientCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MessageClientCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MESSAGE_CLIENT_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MessageClientCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MessageClientCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MESSAGE_CLIENT_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MESSAGE_CLIENT_CORE_LIB_H
