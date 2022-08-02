///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 23:30)

#ifndef UPDATE_SERVER_CORE_LIB_H
#define UPDATE_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_UPDATE_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UpdateServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UpdateServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_UPDATE_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "UpdateServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UpdateServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_UPDATE_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // UPDATE_SERVER_CORE_LIB_H
