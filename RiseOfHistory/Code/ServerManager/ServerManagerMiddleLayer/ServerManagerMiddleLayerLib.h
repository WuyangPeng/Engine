/// Copyright (c) 2010-2025
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.2.0 (2025/01/06 09:56)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_LIB_H
#define SERVER_MANAGER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SERVER_MANAGER_MIDDLE_LAYER_LIB_H