///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:26)

#ifndef CPP_THE_CORE_LANGUAGE_LIB_H
#define CPP_THE_CORE_LANGUAGE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppTheCoreLanguageD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTheCoreLanguage.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppTheCoreLanguageStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTheCoreLanguageStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_THE_CORE_LANGUAGE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_THE_CORE_LANGUAGE_LIB_H
