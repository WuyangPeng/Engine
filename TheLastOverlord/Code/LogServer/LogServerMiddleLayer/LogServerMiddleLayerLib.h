///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 21:32)

#ifndef LOG_SERVER_MIDDLE_LAYER_LIB_H
#define LOG_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

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
