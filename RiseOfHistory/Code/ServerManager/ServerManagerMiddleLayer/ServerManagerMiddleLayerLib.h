/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/06/20 15:15)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_LIB_H
#define SERVER_MANAGER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ServerManagerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SERVER_MANAGER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SERVER_MANAGER_MIDDLE_LAYER_LIB_H