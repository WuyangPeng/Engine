/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 20:11)

#ifndef SCRIPT_LIB_H
#define SCRIPT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCRIPT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Script.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SCRIPT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ScriptStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SCRIPT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_LIB_H