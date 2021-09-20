///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:26)

#ifndef ALGORITHMS_IN_CPP_PARTS_5_LIB_H
#define ALGORITHMS_IN_CPP_PARTS_5_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsInCppParts5D.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsInCppParts5.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AlgorithmsInCppParts5StaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AlgorithmsInCppParts5Static.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ALGORITHMS_IN_CPP_PARTS_5_LIB_H
