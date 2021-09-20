///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/15 1:02)

#ifndef BOOK_ALGORITHM_TOOLSET_LIB_H
#define BOOK_ALGORITHM_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookAlgorithmToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAlgorithmToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookAlgorithmToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookAlgorithmToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_ALGORITHM_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_ALGORITHM_TOOLSET_LIB_H
