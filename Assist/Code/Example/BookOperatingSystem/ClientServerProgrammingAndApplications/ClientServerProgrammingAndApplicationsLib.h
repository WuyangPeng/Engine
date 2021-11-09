///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:44)

#ifndef CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_LIB_H
#define CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ClientServerProgrammingAndApplicationsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ClientServerProgrammingAndApplications.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ClientServerProgrammingAndApplicationsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ClientServerProgrammingAndApplicationsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CLIENT_SERVER_PROGRAMMING_AND_APPLICATIONS_LIB_H
