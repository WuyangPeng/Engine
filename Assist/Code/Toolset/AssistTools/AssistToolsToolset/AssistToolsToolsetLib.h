///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:37)

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
