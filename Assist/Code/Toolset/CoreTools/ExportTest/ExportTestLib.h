///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/16 21:44)

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