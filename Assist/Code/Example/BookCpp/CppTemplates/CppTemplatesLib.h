///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/07 18:48)

#ifndef CPP_TEMPLATES_LIB_H
#define CPP_TEMPLATES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_TEMPLATES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplatesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplates.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_TEMPLATES_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplatesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplatesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_TEMPLATES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_TEMPLATES_LIB_H
