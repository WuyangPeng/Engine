///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.4 (2023/03/17 17:23)

#ifndef JSON_CONFIGURE_LIB_H
#define JSON_CONFIGURE_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "JsonConfigureD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "JsonConfigure.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "JsonConfigureStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "JsonConfigureStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // JSON_CONFIGURE_LIB_H