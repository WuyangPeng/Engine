///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:45)

#ifndef MORE_EFFECTIVE_CPP_LIB_H
#define MORE_EFFECTIVE_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MORE_EFFECTIVE_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MoreEffectiveCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MoreEffectiveCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MORE_EFFECTIVE_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MoreEffectiveCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MoreEffectiveCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MORE_EFFECTIVE_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MORE_EFFECTIVE_CPP_LIB_H
