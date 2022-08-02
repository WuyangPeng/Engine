///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 21:11)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MessageClientMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MessageClientMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MessageClientMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MessageClientMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H
