///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 12:28)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H
#define RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H

#include "System/Helper/EnumOperator.h"

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
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_TYPES_H
