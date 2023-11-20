/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef LOG_SERVER_CORE_LIB_H
#define LOG_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LOG_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LOG_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LOG_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LOG_SERVER_CORE_LIB_H