///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_LIB_H
#define ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ElementaryNumberTheoryAndItsApplicationsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ElementaryNumberTheoryAndItsApplications.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ElementaryNumberTheoryAndItsApplicationsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ElementaryNumberTheoryAndItsApplicationsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ELEMENTARY_NUMBER_THEORY_AND_ITS_APPLICATIONS_LIB_H
