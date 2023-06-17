///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H
#define RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersInternalFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingEnvironmentFactory
    {
    public:
        using ClassType = RenderingEnvironmentFactory;
        using RenderingEnvironmentSharedPtr = std::shared_ptr<RenderingEnvironmentImpl>;

    private:
        RenderingEnvironmentFactory() noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static RenderingEnvironmentSharedPtr Create(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter);
    };
}

#endif  // RENDERING_RENDERERS_RENDERING_ENVIRONMENT_FACTORY_H
