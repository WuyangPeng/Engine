///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:44)

#ifndef INPUT_OUTPUT_TOOLSET_LIB_H
#define INPUT_OUTPUT_TOOLSET_LIB_H

#include "InputOutput/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INPUT_OUTPUT_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "InputOutputToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InputOutputToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INPUT_OUTPUT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "InputOutputToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InputOutputToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INPUT_OUTPUT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INPUT_OUTPUT_TOOLSET_LIB_H
