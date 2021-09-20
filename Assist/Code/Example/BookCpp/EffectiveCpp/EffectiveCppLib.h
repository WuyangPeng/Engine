///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:45)

#ifndef EFFECTIVE_CPP_LIB_H
#define EFFECTIVE_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EFFECTIVE_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EFFECTIVE_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EFFECTIVE_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EFFECTIVE_CPP_LIB_H
