///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/07 18:48)

#ifndef CPP_TEMPLATES_LIB_H
#define CPP_TEMPLATES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_TEMPLATES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplatesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplates.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_TEMPLATES_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppTemplatesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTemplatesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_TEMPLATES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_TEMPLATES_LIB_H
