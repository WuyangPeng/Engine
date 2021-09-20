///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/24 22:47)

#ifndef CPP_PRIMER_FIFTH_EDITION_LIB_H
#define CPP_PRIMER_FIFTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerFifthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerFifthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerFifthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerFifthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_PRIMER_FIFTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_PRIMER_FIFTH_EDITION_LIB_H
