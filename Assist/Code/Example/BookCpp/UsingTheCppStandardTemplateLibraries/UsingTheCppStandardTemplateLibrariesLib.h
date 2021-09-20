///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/06 16:29)

#ifndef USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_LIB_H
#define USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UsingTheCppStandardTemplateLibrariesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UsingTheCppStandardTemplateLibraries.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "UsingTheCppStandardTemplateLibrariesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UsingTheCppStandardTemplateLibrariesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USING_THE_CPP_STANDARD_TEMPLATE_LIBRARIES_LIB_H
