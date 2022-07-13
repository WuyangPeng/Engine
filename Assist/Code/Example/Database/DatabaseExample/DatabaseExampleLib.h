///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 11:04)

#ifndef DATABASE_EXAMPLE_LIB_H
#define DATABASE_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

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
