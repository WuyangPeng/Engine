/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:48)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_LIB_H
#define DATABASE_GENERATE_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_GENERATE_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_LIB_H