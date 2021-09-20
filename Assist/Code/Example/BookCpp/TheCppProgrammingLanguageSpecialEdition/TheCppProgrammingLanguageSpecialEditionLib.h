///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/08 21:28)

#ifndef THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_LIB_H
#define THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageSpecialEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_CPP_PROGRAMMING_LANGUAGE_SPECIAL_EDITION_LIB_H
