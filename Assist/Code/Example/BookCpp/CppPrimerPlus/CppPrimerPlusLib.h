///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/28 20:45)

#ifndef CPP_PRIMER_PLUS_LIB_H
#define CPP_PRIMER_PLUS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_PRIMER_PLUS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerPlusD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerPlus.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_PRIMER_PLUS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppPrimerPlusStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppPrimerPlusStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_PRIMER_PLUS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_PRIMER_PLUS_LIB_H
