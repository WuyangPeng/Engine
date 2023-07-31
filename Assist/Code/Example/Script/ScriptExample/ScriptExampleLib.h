///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 11:05)

#ifndef SCRIPT_EXAMPLE_LIB_H
#define SCRIPT_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptExampleD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ScriptExample.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SCRIPT_EXAMPLE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ScriptExampleStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ScriptExampleStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SCRIPT_EXAMPLE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_EXAMPLE_LIB_H
