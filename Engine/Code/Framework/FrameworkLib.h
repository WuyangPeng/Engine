///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/18 16:32)

#ifndef FRAMEWORK_LIB_H
#define FRAMEWORK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FRAMEWORK_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "FrameworkD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Framework.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_FRAMEWORK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_FRAMEWORK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FRAMEWORK_LIB_H
