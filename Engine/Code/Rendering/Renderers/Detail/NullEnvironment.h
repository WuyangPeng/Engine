///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/06 14:29)

#ifndef RENDERING_OPENGL_RENDERER_NULL_ENVIRONMENT_H
#define RENDERING_OPENGL_RENDERER_NULL_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/RenderingEnvironmentImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullEnvironment : public RenderingEnvironmentImpl
    {
    public:
        using ClassType = NullEnvironment;
        using ParentType = RenderingEnvironmentImpl;

    public:
        explicit NullEnvironment(const RendererParameter& rendererParameter) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingEnvironmentSharedPtr Clone() const override;

        void InitEnvironment() noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_NULL_ENVIRONMENT_H
