///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 15:36)

#ifndef ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H
#define ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H

#include "ArtificialIntellegence/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ArtificialIntellegenceToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ArtificialIntellegenceToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ArtificialIntellegenceToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ArtificialIntellegenceToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ARTIFICIAL_INTELLEGENCE_TOOLSET_LIB_H
