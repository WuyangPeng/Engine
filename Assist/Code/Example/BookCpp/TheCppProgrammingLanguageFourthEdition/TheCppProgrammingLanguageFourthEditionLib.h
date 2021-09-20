///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/08 21:28)

#ifndef THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_LIB_H
#define THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageFourthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageFourthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageFourthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheCppProgrammingLanguageFourthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_CPP_PROGRAMMING_LANGUAGE_FOURTH_EDITION_LIB_H