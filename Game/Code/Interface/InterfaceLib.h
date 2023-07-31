///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:53)

#ifndef INTERFACE_LIB_H
#define INTERFACE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INTERFACE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "InterfaceD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Interface.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_INTERFACE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "InterfaceStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InterfaceStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_INTERFACE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INTERFACE_LIB_H
