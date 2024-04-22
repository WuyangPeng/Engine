/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:42)

#ifndef CSV_CONFIGURE_LIB_H
#define CSV_CONFIGURE_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CSVConfigureD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CSVConfigure.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CSVConfigureStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CSVConfigureStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CSV_CONFIGURE_LIB_H