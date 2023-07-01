///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 21:31)

#ifndef DATABASE_GENERATE_SERVER_CORE_LIB_H
#define DATABASE_GENERATE_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_SERVER_CORE_LIB_H