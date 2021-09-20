///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/08 21:39)

#ifndef PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_LIB_H
#define PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingApplicationsForMicrosoftWindowsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingApplicationsForMicrosoftWindows.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingApplicationsForMicrosoftWindowsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingApplicationsForMicrosoftWindowsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROGRAMMING_APPLICATIONS_FOR_MICROSOFT_WINDOWS_LIB_H
