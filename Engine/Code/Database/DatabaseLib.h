///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/24 17:24)

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