///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 10:10)

#ifndef RENDERING_RENDERERS_RENDERER_TYPES_H
#define RENDERING_RENDERERS_RENDERER_TYPES_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace Rendering
{
    enum class RendererTypes
    {
        First = 0,

        Default = First,
        Windows = 1,
        Glut = 2,
        Glfw = 3,
        OpenGL = 4,
        OpenGLES = 5,
        Vulkan = 6,
        Dx11 = 7,
        Dx12 = 8,
        Non,

        Max,
    };

    ENUM_RIGHT_SHIFTABLE_OPERATOR_DEFINE(RendererTypes);
}

#endif  // RENDERING_RENDERERS_RENDERER_TYPES_H
