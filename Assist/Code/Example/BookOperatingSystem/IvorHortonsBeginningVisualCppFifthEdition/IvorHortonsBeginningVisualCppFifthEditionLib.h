///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/19 23:07)

#ifndef IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_LIB_H
#define IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppFifthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppFifthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppFifthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppFifthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_FIFTH_EDITION_LIB_H
