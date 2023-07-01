///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:29)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_ENVIRONMENT_H
#define RENDERING_OPENGL_RENDERER_OPENGL_ENVIRONMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/Detail/RenderingEnvironmentImpl.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

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
