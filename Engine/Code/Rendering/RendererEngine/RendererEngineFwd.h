///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:19)

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