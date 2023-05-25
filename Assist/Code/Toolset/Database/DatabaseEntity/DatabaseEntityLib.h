///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.9 (2023/05/25 11:24)

#ifndef DATABASE_ENTITY_LIB_H
#define DATABASE_ENTITY_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseEntityD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseEntity.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseEntityStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseEntityStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_ENTITY_LIB_H