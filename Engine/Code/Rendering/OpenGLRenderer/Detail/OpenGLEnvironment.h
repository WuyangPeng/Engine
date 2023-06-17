///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_ENVIRONMENT_H
#define RENDERING_OPENGL_RENDERER_OPENGL_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/RenderingEnvironmentImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLEnvironment : public RenderingEnvironmentImpl
    {
    public:
        using ClassType = OpenGLEnvironment;
        using ParentType = RenderingEnvironmentImpl;

    public:
        explicit OpenGLEnvironment(const RendererParameter& rendererParameter) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingEnvironmentSharedPtr Clone() const override;

        void InitEnvironment() override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_ENVIRONMENT_H
