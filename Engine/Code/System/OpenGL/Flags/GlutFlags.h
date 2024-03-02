/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 16:49)

#ifndef SYSTEM_OPENGL_GLUT_FLAGS_H
#define SYSTEM_OPENGL_GLUT_FLAGS_H

#include "System/Helper/EnumOperator.h"

#include "System/Helper/Platform.h"

#if defined(SYSTEM_USE_GLUT) && defined(WIN32)

    #include "System/Helper/PragmaWarning/Freeglut.h"

#endif  // defined(SYSTEM_USE_GLUT) && defined(WIN32)

#if defined(SYSTEM_USE_GLUT) && defined(WIN32)

namespace System
{
    enum class GlutMacro
    {
        Rgb = GLUT_RGB,
        Rgba = GLUT_RGBA,
        Index = GLUT_INDEX,
        Single = GLUT_SINGLE,
        Double = GLUT_DOUBLE,
        Accumulation = GLUT_ACCUM,
        Alpha = GLUT_ALPHA,
        Depth = GLUT_DEPTH,
        Stencil = GLUT_STENCIL,
        MultiSample = GLUT_MULTISAMPLE,
        Stereo = GLUT_STEREO,
        Luminance = GLUT_LUMINANCE,
    };

    enum class GlutOption
    {
        WindowClose = GLUT_ACTION_ON_WINDOW_CLOSE,
    };

    enum class GlutExtension
    {
        GlutMainLoopReturns = GLUT_ACTION_GLUTMAINLOOP_RETURNS,
    };
}

#else  // !defined(SYSTEM_USE_GLUT) || !defined(WIN32)

namespace System
{
    enum class GlutMacro
    {
        Rgb = 0x0000,
        Rgba = 0x0000,
        Index = 0x0001,
        Single = 0x0000,
        Double = 0x0002,
        Accumulation = 0x0004,
        Alpha = 0x0008,
        Depth = 0x0010,
        Stencil = 0x0020,
        MultiSample = 0x0080,
        Stereo = 0x0100,
        Luminance = 0x0200,
    };

    enum class GlutOption
    {
        WindowClose = 0x01F9,
    };

    enum class GlutExtension
    {
        GlutMainLoopReturns = 1,
    };
}

#endif  // defined(SYSTEM_USE_GLUT) && defined(WIN32)

#endif  // SYSTEM_OPENGL_GLUT_FLAGS_H
