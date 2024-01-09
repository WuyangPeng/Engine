/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 16:47)

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
