/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 15:38)

#ifndef INPUT_OUTPUT_LIB_H
#define INPUT_OUTPUT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INPUT_OUTPUT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "InputOutputD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InputOutput.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_INPUT_OUTPUT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "InputOutputStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InputOutputStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_INPUT_OUTPUT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INPUT_OUTPUT_LIB_H