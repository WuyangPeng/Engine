///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/23 9:11)

#ifndef BOOK_NETWORK_PROGRAMMING_TOOLSET_LIB_H
#define BOOK_NETWORK_PROGRAMMING_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookNetworkProgrammingToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookNetworkProgrammingToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookNetworkProgrammingToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookNetworkProgrammingToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_NETWORK_PROGRAMMING_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_NETWORK_PROGRAMMING_TOOLSET_LIB_H
