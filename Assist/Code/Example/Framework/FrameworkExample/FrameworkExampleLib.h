///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 11:51)

#ifndef FRAMEWORK_EXAMPLE_LIB_H
#define FRAMEWORK_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "FrameworkExampleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FrameworkExample.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_FRAMEWORK_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "FrameworkExampleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FrameworkExampleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_FRAMEWORK_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FRAMEWORK_EXAMPLE_LIB_H
