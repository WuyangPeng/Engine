///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:46)

#ifndef EFFECTIVE_MODERN_CPP_LIB_H
#define EFFECTIVE_MODERN_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EFFECTIVE_MODERN_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveModernCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveModernCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EFFECTIVE_MODERN_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveModernCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveModernCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EFFECTIVE_MODERN_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EFFECTIVE_MODERN_CPP_LIB_H
