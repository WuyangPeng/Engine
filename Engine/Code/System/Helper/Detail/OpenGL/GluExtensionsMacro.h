//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:50)

#ifndef SYSTEM_HELPER_GLU_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GLU_EXTENSIONS_MACRO_H

#include "System/SystemDll.h"

#include "System/Helper/ConfigMacro.h"

#ifdef SYSTEM_PLATFORM_WIN32

    // Microsoft Windows
    #ifndef APIENTRY
        #define SYSTEM_DEFINED_APIENTRY
        #define APIENTRY __stdcall
    #endif  // APIENTRY

    #ifndef CALLBACK
        #define SYSTEM_DEFINED_CALLBACK
        #define CALLBACK __stdcall
    #endif  // CALLBACK

    #ifndef GLAPI
        #define SYSTEM_DEFINED_GLAPI
        #define GLAPI extern
    #endif  // GLAPI

#else  // !SYSTEM_PLATFORM_WIN32

    // Macintosh, Linux
    #define APIENTRY
    #define CALLBACK

#endif  // SYSTEM_PLATFORM_WIN32

#ifdef SYSTEM_PLATFORM_MACOS
    #include <OpenGL/glu.h>
#else  // !SYSTEM_PLATFORM_MACOS
    #include <GL/glu.h>
#endif  // SYSTEM_PLATFORM_MACOS

#ifdef SYSTEM_DEFINED_APIENTRY
    #undef APIENTRY
#endif  // SYSTEM_DEFINED_APIENTRY

#ifdef SYSTEM_DEFINED_CALLBACK
    #undef CALLBACK
#endif  // SYSTEM_DEFINED_CALLBACK

#ifdef SYSTEM_DEFINED_GLAPI
    #undef GLAPI
#endif  // SYSTEM_DEFINED_GLAPI

#endif  // SYSTEM_HELPER_GLU_EXTENSIONS_MACRO_H
