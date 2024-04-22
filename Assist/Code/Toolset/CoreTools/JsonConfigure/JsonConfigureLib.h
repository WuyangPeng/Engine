/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 17:47)

#ifndef JSON_CONFIGURE_LIB_H
#define JSON_CONFIGURE_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "JsonConfigureD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "JsonConfigure.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "JsonConfigureStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "JsonConfigureStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // JSON_CONFIGURE_LIB_H