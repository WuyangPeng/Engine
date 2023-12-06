/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef LOG_SERVER_MIDDLE_LAYER_LIB_H
#define LOG_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LOG_SERVER_MIDDLE_LAYER_LIB_H