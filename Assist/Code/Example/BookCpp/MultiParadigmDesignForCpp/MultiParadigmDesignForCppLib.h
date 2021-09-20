///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef MULTI_PARADIGM_DESIGN_FOR_CPP_LIB_H
#define MULTI_PARADIGM_DESIGN_FOR_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MultiParadigmDesignForCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultiParadigmDesignForCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "MultiParadigmDesignForCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MultiParadigmDesignForCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MULTI_PARADIGM_DESIGN_FOR_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MULTI_PARADIGM_DESIGN_FOR_CPP_LIB_H
