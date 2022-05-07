///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 15:54)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/VertexShader.h"

namespace Rendering
{
    class PdrVertexShader : public OpenGLShader
    {
    public:
        using ClassType = PdrVertexShader;
        using ParentType = OpenGLShader;

    public:
        PdrVertexShader(Renderer* renderer, const VertexShader* vshader) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer, const VertexShader* vshader, const ShaderParameters* parameters) noexcept;
        void Disable(Renderer* renderer, const VertexShader* vshader, const ShaderParameters* parameters) noexcept;

    private:
        GLuint shader = 0;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
