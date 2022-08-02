///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 15:28)

#ifndef ROBOT_CLIENT_CORE_LIB_H
#define ROBOT_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ROBOT_CLIENT_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "RobotClientCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RobotClientCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ROBOT_CLIENT_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "RobotClientCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "RobotClientCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ROBOT_CLIENT_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ROBOT_CLIENT_CORE_LIB_H
