///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 12:35)

#ifndef SYSTEM_DLL_LIB_H
#define SYSTEM_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")

    #if !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)
        #pragma comment(lib, "opengl32.lib")
    #endif  // !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)

#endif  // TCRE_USE_MSVC

#endif  // SYSTEM_DLL_LIB_H