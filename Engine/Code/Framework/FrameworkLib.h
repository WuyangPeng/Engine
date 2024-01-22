/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:10)

#ifndef FRAMEWORK_LIB_H
#define FRAMEWORK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FRAMEWORK_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "FrameworkD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Framework.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_FRAMEWORK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_FRAMEWORK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FRAMEWORK_LIB_H
