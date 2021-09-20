///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef NUMERICAL_RECIPES_IN_CPP_LIB_H
#define NUMERICAL_RECIPES_IN_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_NUMERICAL_RECIPES_IN_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "NumericalRecipesInCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NumericalRecipesInCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_NUMERICAL_RECIPES_IN_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "NumericalRecipesInCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "NumericalRecipesInCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_NUMERICAL_RECIPES_IN_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // NUMERICAL_RECIPES_IN_CPP_LIB_H
