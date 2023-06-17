///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/PixelShader.h"

namespace Rendering
{
    class PdrPixelShader : public OpenGLShader
    {
    public:
        using ClassType = PdrPixelShader;
        using ParentType = OpenGLShader;

    public:
        PdrPixelShader(Renderer* renderer, const PixelShader* pshader) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters) noexcept;
        void Disable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters) noexcept;

    private:
        GLuint shader = 0;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
