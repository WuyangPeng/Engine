///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:26)

#ifndef STATUS_LIB_H
#define STATUS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATUS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "StatusD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Status.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATUS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "StatusStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "StatusStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATUS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // STATUS_LIB_H
