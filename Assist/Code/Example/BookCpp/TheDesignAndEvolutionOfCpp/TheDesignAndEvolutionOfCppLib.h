///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:51)

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
