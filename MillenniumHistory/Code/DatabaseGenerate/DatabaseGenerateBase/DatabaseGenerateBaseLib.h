/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/22 22:31)

#ifndef DATABASE_GENERATE_BASE_LIB_H
#define DATABASE_GENERATE_BASE_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateBaseD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateBase.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateBaseStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateBaseStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_BASE_LIB_H