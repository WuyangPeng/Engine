///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 17:12)

#ifndef ACTIVITY_LIB_H
#define ACTIVITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ACTIVITY_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ActivityD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Activity.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ACTIVITY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ActivityStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ActivityStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ACTIVITY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ACTIVITY_LIB_H
