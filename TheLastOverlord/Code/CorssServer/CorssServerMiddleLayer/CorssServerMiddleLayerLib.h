/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#ifndef CORSS_SERVER_MIDDLE_LAYER_LIB_H
#define CORSS_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CorssServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CorssServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CorssServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CorssServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CORSS_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORSS_SERVER_MIDDLE_LAYER_LIB_H