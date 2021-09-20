///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:46)

#ifndef THE_ACE_PROGRAMMERS_GUIDE_LIB_H
#define THE_ACE_PROGRAMMERS_GUIDE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheACEProgrammersGuideD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheACEProgrammersGuide.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "TheACEProgrammersGuideStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheACEProgrammersGuideStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_ACE_PROGRAMMERS_GUIDE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_ACE_PROGRAMMERS_GUIDE_LIB_H
