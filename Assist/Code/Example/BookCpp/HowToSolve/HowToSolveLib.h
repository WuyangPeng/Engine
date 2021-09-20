///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef HOW_TO_SOLVE_LIB_H
#define HOW_TO_SOLVE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_HOW_TO_SOLVE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "HowToSolveD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "HowToSolve.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_HOW_TO_SOLVE_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "HowToSolveStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "HowToSolveStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_HOW_TO_SOLVE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // HOW_TO_SOLVE_LIB_H
