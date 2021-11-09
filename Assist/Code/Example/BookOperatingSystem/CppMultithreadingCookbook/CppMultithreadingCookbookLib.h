///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#ifndef CPP_MULTITHREADING_COOKBOOK_LIB_H
#define CPP_MULTITHREADING_COOKBOOK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppMultithreadingCookbookD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppMultithreadingCookbook.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppMultithreadingCookbookStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppMultithreadingCookbookStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_MULTITHREADING_COOKBOOK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_MULTITHREADING_COOKBOOK_LIB_H
