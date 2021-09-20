///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/05 0:33)

#ifndef BOOK_INTERMEDIATE_LIB_H
#define BOOK_INTERMEDIATE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_INTERMEDIATE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookIntermediateD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookIntermediate.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_INTERMEDIATE_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BookIntermediateStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookIntermediateStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_INTERMEDIATE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_INTERMEDIATE_LIB_H
