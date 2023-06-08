///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ������汾��0.9.0.11 (2023/06/04 18:18)

#ifndef DATABASE_GENERATE_SERVER_CONFIGURATION_LIB_H
#define DATABASE_GENERATE_SERVER_CONFIGURATION_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateServerConfigurationD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateServerConfiguration.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateServerConfigurationStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateServerConfigurationStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_SERVER_CONFIGURATION_LIB_H