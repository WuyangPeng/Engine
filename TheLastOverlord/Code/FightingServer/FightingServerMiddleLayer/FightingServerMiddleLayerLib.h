/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/18 17:09)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_LIB_H
#define FIGHTING_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "FightingServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FightingServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "FightingServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FightingServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FIGHTING_SERVER_MIDDLE_LAYER_LIB_H