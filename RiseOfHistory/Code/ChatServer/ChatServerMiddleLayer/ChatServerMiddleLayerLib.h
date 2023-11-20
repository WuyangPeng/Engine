/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#ifndef CHAT_SERVER_MIDDLE_LAYER_LIB_H
#define CHAT_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

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