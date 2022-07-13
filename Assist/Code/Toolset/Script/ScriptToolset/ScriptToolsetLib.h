///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 16:37)

#ifndef SCRIPT_TOOLSET_LIB_H
#define SCRIPT_TOOLSET_LIB_H

#include "Script/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCRIPT_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ScriptToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ScriptToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SCRIPT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ScriptToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ScriptToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SCRIPT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_TOOLSET_LIB_H
