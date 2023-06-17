///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 13:30)

#ifndef TIME_REFRESH_LIB_H
#define TIME_REFRESH_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_TIME_REFRESH_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "TimeRefreshD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TimeRefresh.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_TIME_REFRESH_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "TimeRefreshStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "TimeRefreshStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_TIME_REFRESH_STATIC

#endif  // TCRE_USE_MSVC

#endif  // TIME_REFRESH_LIB_H
