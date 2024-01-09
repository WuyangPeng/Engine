/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 14:09)

#ifndef RENDERING_RENDERER_ENGINE_FWD_H
#define RENDERING_RENDERER_ENGINE_FWD_H

#include <memory>

namespace Rendering
{
    enum class RendererTypes;

    class Viewport;
    class DepthRange;
    class RendererBasis;
    class WindowsParameter;
    class RendererParameter;
    class EnvironmentParameter;
    class RenderingEnvironment;
    class RenderingDevice;
    class BaseRenderer;
    class PickRay;
}

#endif  // RENDERING_RENDERER_ENGINE_FWD_H