///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 17:02)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_LIB_H
#define ROBOT_CLIENT_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RobotClientMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RobotClientMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RobotClientMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RobotClientMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ROBOT_CLIENT_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ROBOT_CLIENT_MIDDLE_LAYER_LIB_H
