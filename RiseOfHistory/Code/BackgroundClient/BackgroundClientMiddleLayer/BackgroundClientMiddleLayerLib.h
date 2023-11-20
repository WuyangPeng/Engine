/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "BackgroundClientMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "BackgroundClientMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "BackgroundClientMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "BackgroundClientMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H