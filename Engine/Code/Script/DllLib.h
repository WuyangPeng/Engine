//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 14:32)

#ifndef SCRIPT_DLL_LIB_H
#define SCRIPT_DLL_LIB_H

#include "Helper/UserMacro.h"
#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef SCRIPT_USE_LUA
        #pragma comment(lib, "lua.lib")
    #endif  // SCRIPT_USE_LUA

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_DLL_LIB_H