///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/23 16:05)

#ifndef HOW_NOT_TO_PROGRAM_IN_CPP_LIB_H
#define HOW_NOT_TO_PROGRAM_IN_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "HowNotToProgramInCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "HowNotToProgramInCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "HowNotToProgramInCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "HowNotToProgramInCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // HOW_NOT_TO_PROGRAM_IN_CPP_LIB_H
