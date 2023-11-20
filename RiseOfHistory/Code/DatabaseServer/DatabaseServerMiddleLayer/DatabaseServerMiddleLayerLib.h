/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.0 (2023/11/19 00:20)

#ifndef DATABASE_SERVER_MIDDLE_LAYER_LIB_H
#define DATABASE_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

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

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_SERVER_MIDDLE_LAYER_LIB_H