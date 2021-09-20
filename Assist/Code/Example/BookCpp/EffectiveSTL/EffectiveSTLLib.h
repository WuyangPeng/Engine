///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:45)

#ifndef EFFECTIVE_STL_LIB_H
#define EFFECTIVE_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EFFECTIVE_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EFFECTIVE_STL_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "EffectiveSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "EffectiveSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EFFECTIVE_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EFFECTIVE_STL_LIB_H
