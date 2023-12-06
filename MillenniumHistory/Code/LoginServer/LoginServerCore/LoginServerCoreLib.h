/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef LOGIN_SERVER_CORE_LIB_H
#define LOGIN_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LOGIN_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LoginServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LoginServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LOGIN_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LoginServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LoginServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LOGIN_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LOGIN_SERVER_CORE_LIB_H