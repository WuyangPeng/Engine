///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class PdrVertexShader : public OpenGLShader
    {
    public:
        using ClassType = PdrVertexShader;
        using ParentType = OpenGLShader;

    public:
        PdrVertexShader(BaseRenderer* renderer) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(BaseRenderer* renderer) noexcept;
        void Disable(BaseRenderer* renderer) noexcept;

    private:
        GLuint shader = 0;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
