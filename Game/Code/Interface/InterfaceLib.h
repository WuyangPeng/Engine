///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:50)

#ifndef ACTIVITY_LIB_H
#define ACTIVITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ACTIVITY_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "InterfaceD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Interface.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ACTIVITY_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "InterfaceStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InterfaceStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ACTIVITY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ACTIVITY_LIB_H
