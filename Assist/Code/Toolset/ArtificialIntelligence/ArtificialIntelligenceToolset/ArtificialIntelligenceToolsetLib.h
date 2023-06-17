///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 19:36)

#ifndef ARTIFICIAL_INTELLIGENCE_TOOLSET_LIB_H
#define ARTIFICIAL_INTELLIGENCE_TOOLSET_LIB_H

#include "ArtificialIntelligence/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ArtificialIntelligenceToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ArtificialIntelligenceToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ArtificialIntelligenceToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ArtificialIntelligenceToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ARTIFICIAL_INTELLIGENCE_TOOLSET_LIB_H
