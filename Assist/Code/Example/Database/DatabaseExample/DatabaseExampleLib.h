///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:51)

#ifndef DATABASE_EXAMPLE_LIB_H
#define DATABASE_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_EXAMPLE_LIB_H
