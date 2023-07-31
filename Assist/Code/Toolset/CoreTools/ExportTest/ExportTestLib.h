///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:53)

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