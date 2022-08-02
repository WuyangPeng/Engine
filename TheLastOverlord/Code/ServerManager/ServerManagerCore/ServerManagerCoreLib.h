///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 23:07)

#ifndef SERVER_MANAGER_CORE_LIB_H
#define SERVER_MANAGER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ServerManagerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ServerManagerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SERVER_MANAGER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ServerManagerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ServerManagerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SERVER_MANAGER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SERVER_MANAGER_CORE_LIB_H
