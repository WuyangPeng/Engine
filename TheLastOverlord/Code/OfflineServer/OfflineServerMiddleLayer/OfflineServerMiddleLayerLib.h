///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/26 19:16)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_LIB_H
#define OFFLINE_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "OfflineServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OfflineServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "OfflineServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OfflineServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_OFFLINE_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // OFFLINE_SERVER_MIDDLE_LAYER_LIB_H
