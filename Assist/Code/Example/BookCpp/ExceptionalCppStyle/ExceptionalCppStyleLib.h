///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/20 0:14)

#ifndef EXCEPTIONAL_CPP_STYLE_LIB_H
#define EXCEPTIONAL_CPP_STYLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ExceptionalCppStyleD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExceptionalCppStyle.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ExceptionalCppStyleStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExceptionalCppStyleStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EXCEPTIONAL_CPP_STYLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EXCEPTIONAL_CPP_STYLE_LIB_H
