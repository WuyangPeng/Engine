///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef THE_DESIGN_AND_EVOLUTION_OF_CPP_LIB_H
#define THE_DESIGN_AND_EVOLUTION_OF_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheDesignAndEvolutionOfCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheDesignAndEvolutionOfCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheDesignAndEvolutionOfCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheDesignAndEvolutionOfCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_DESIGN_AND_EVOLUTION_OF_CPP_LIB_H
