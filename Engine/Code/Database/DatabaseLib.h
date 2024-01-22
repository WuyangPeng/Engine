/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 13:29)

#ifndef DATABASE_LIB_H
#define DATABASE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Database.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_LIB_H