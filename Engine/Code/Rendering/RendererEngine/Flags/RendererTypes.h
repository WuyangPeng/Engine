/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 14:09)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H
#define RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H

#include "System/Helper/EnumOperator.h"

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
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H
