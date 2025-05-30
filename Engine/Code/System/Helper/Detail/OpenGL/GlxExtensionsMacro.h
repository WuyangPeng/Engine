/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:53)

#ifndef SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H
#define SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H

#include "System/Helper/GLExtensionsMacro.h"

#ifdef SYSTEM_PLATFORM_LINUX

    #include <X11/Xlib.h>

    #include <GL/glx.h>
    #include <GL/glxext.h>

    #undef InputOutput
    #undef None

#endif  // SYSTEM_PLATFORM_LINUX

#endif  // SYSTEM_HELPER_GLX_EXTENSIONS_MACRO_H
