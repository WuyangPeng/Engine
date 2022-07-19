///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 14:40)

#ifndef ACTIVITY_LIB_H
#define ACTIVITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ACTIVITY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TimeRefreshD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TimeRefresh.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ACTIVITY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TimeRefreshStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TimeRefreshStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ACTIVITY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ACTIVITY_LIB_H
