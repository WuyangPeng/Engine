///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:48)

#ifndef INSTANCE_LIB_H
#define INSTANCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INSTANCE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "InstanceD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Instance.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_INSTANCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "InstanceStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InstanceStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_INSTANCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INSTANCE_LIB_H
