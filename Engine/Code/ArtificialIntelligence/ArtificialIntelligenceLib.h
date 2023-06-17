///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 19:29)

#ifndef ARTIFICIAL_INTELLIGENCE_LIB_H
#define ARTIFICIAL_INTELLIGENCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ArtificialIntelligenceD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ArtificialIntelligence.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ArtificialIntelligenceStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ArtificialIntelligenceStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ARTIFICIAL_INTELLIGENCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ARTIFICIAL_INTELLIGENCE_LIB_H