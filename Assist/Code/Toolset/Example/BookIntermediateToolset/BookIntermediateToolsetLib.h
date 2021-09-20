///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/24 16:24)

#ifndef BOOK_INTERMEDIATE_TOOLSET_LIB_H
#define BOOK_INTERMEDIATE_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookIntermediateToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookIntermediateToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookIntermediateToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookIntermediateToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_INTERMEDIATE_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_INTERMEDIATE_TOOLSET_LIB_H
