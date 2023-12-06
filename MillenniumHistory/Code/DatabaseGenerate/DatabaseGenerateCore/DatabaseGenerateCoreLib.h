/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef DATABASE_GENERATE_CORE_LIB_H
#define DATABASE_GENERATE_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_GENERATE_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_GENERATE_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_GENERATE_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_CORE_LIB_H