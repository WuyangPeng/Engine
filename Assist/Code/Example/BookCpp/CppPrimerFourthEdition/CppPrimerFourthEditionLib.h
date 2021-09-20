///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/24 22:00)

#ifndef CPP_PRIMER_FOURTH_EDITION_LIB_H
#define CPP_PRIMER_FOURTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerFourthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerFourthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerFourthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerFourthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_PRIMER_FOURTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_PRIMER_FOURTH_EDITION_LIB_H
