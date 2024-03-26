/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:22)

#ifndef EXPORT_TEST_LIB_H
#define EXPORT_TEST_LIB_H

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ExportTestD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ExportTest.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ExportTestStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ExportTestStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EXPORT_TEST_LIB_H