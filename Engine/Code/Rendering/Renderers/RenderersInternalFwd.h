///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/06 14:17)

#ifndef RENDERING_RENDERERS_INTERNAL_FWD_H
#define RENDERING_RENDERERS_INTERNAL_FWD_H

#include "RenderersFwd.h"

namespace Rendering
{
    class RenderingEnvironmentImpl;
    class RenderingEnvironmentFactory;
    class EnvironmentParameterImpl;
    class EnvironmentParameterFactory;
    class RenderingDeviceImpl;
    class RenderingDeviceFactory;

    using PlatformTexture2DSharedPtr = std::shared_ptr<PlatformTexture2D>;

    class RendererParameterImpl;

    class RendererFactory;

    class RendererImpl;
    class RendererInputImpl;
}

#endif  // RENDERING_RENDERERS_INTERNAL_FWD_H