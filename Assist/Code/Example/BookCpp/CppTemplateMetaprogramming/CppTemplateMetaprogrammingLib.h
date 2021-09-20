///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/07 18:48)

#ifndef CPP_TEMPLATE_METAPROGRAMMING_LIB_H
#define CPP_TEMPLATE_METAPROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplateMetaprogrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplateMetaprogramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplateMetaprogrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplateMetaprogrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_TEMPLATE_METAPROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_TEMPLATE_METAPROGRAMMING_LIB_H
