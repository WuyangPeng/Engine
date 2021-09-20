///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/22 22:04)

#ifndef THINKING_IN_CPP_VOLUME_ONE_LIB_H
#define THINKING_IN_CPP_VOLUME_ONE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeOneD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeOne.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeOneStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingInCppVolumeOneStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THINKING_IN_CPP_VOLUME_ONE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THINKING_IN_CPP_VOLUME_ONE_LIB_H
