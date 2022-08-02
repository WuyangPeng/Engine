///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/27 21:13)

#ifndef CHAT_SERVER_MIDDLE_LAYER_LIB_H
#define CHAT_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CHAT_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ChatServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ChatServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CHAT_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ChatServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ChatServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CHAT_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CHAT_SERVER_MIDDLE_LAYER_LIB_H