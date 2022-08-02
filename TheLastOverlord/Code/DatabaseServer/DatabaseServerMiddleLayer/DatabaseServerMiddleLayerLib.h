///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/29 20:58)

#ifndef DATABASE_SERVER_MIDDLE_LAYER_LIB_H
#define DATABASE_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(_MSC_VER)

    #ifndef BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DatabaseServerMiddleLayerD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DatabaseServerMiddleLayer.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "DatabaseServerMiddleLayerStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DatabaseServerMiddleLayerStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_SERVER_MIDDLE_LAYER_STATIC

#endif  // _MSC_VER

#endif  // DATABASE_SERVER_MIDDLE_LAYER_LIB_H