///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 15:49) 

#ifndef ASSIST_TOOLS_TOOLSET_LIB_H
#define ASSIST_TOOLS_TOOLSET_LIB_H

#include "AssistTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ASSIST_TOOLS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AssistToolsToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AssistToolsToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ASSIST_TOOLS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AssistToolsToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AssistToolsToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ASSIST_TOOLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ASSIST_TOOLS_TOOLSET_LIB_H
