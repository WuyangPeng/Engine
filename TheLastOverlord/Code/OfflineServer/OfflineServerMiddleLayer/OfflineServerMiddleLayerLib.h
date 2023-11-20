/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_LIB_H
#define OFFLINE_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "OfflineServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "OfflineServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "OfflineServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "OfflineServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // OFFLINE_SERVER_MIDDLE_LAYER_LIB_H