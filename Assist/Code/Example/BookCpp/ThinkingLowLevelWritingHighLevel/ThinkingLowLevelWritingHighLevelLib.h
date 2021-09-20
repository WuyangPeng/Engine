///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#ifndef THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_LIB_H
#define THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingLowLevelWritingHighLevelD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingLowLevelWritingHighLevel.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ThinkingLowLevelWritingHighLevelStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ThinkingLowLevelWritingHighLevelStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THINKING_LOW_LEVEL_WRITING_HIGH_LEVEL_LIB_H
