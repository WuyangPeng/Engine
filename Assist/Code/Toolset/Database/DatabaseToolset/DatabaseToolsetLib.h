///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.9 (2023/05/25 11:26)

#ifndef DATABASE_TOOLSET_LIB_H
#define DATABASE_TOOLSET_LIB_H

#include "Database/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_TOOLSET_LIB_H
