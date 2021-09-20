///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#ifndef ALGORITHMIC_PUZZLES_LIB_H
#define ALGORITHMIC_PUZZLES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMIC_PUZZLES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmicPuzzlesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmicPuzzles.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMIC_PUZZLES_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmicPuzzlesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmicPuzzlesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMIC_PUZZLES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMIC_PUZZLES_LIB_H