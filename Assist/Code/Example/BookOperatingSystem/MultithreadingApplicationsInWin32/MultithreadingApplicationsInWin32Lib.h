///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#ifndef MULTITHREADING_APPLICATIONS_IN_WIN32_LIB_H
#define MULTITHREADING_APPLICATIONS_IN_WIN32_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MultithreadingApplicationsInWin32D.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultithreadingApplicationsInWin32.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MultithreadingApplicationsInWin32StaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultithreadingApplicationsInWin32Static.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MULTITHREADING_APPLICATIONS_IN_WIN32_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MULTITHREADING_APPLICATIONS_IN_WIN32_LIB_H
