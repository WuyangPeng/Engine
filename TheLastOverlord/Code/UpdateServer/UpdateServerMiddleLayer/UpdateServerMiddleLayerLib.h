///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 17:10)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_LIB_H
#define UPDATE_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UpdateServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UpdateServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "UpdateServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UpdateServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // UPDATE_SERVER_MIDDLE_LAYER_LIB_H
