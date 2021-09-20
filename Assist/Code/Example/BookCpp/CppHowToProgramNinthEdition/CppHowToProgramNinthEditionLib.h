///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 1:18)

#ifndef CPP_HOW_TO_PROGRAM_NINTH_EDITION_LIB_H
#define CPP_HOW_TO_PROGRAM_NINTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppHowToProgramNinthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppHowToProgramNinthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppHowToProgramNinthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppHowToProgramNinthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_HOW_TO_PROGRAM_NINTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_HOW_TO_PROGRAM_NINTH_EDITION_LIB_H
