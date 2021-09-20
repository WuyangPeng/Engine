///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:26)

#ifndef ALGORITHMS_FOURTH_EDITION_LIB_H
#define ALGORITHMS_FOURTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsFourthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsFourthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMS_FOURTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMS_FOURTH_EDITION_LIB_H
