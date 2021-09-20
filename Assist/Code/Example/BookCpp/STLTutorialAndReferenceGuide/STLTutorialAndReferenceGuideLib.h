///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/27 22:01)

#ifndef STL_TUTORIAL_AND_REFERENCE_GUIDE_LIB_H
#define STL_TUTORIAL_AND_REFERENCE_GUIDE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "STLTutorialAndReferenceGuideD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "STLTutorialAndReferenceGuide.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "STLTutorialAndReferenceGuideStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "STLTutorialAndReferenceGuideStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_STL_TUTORIAL_AND_REFERENCE_GUIDE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // STL_TUTORIAL_AND_REFERENCE_GUIDE_LIB_H
