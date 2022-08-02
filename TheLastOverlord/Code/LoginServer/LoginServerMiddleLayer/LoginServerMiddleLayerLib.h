///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/24 0:22)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_LIB_H
#define LOGIN_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "LoginServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LoginServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "LoginServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LoginServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_LOGIN_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LOGIN_SERVER_MIDDLE_LAYER_LIB_H
