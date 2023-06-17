///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:59)

#ifndef IMAGICS_LIB_H
#define IMAGICS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IMAGICS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ImagicsD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Imagics.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_IMAGICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ImagicsStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ImagicsStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_IMAGICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IMAGICS_LIB_H