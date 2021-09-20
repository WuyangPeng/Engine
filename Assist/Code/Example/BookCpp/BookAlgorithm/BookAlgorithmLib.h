///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/25 23:57)

#ifndef BOOK_ALGORITHM_LIB_H
#define BOOK_ALGORITHM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_ALGORITHM_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookAlgorithmD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAlgorithm.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_ALGORITHM_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BookAlgorithmStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAlgorithmStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_ALGORITHM_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_ALGORITHM_LIB_H
