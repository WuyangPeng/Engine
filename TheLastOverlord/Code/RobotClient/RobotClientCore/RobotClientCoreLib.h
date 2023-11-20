/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/18 17:09)

#ifndef ROBOT_CLIENT_CORE_LIB_H
#define ROBOT_CLIENT_CORE_LIB_H

#include "Helper/UserMacro.h"

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