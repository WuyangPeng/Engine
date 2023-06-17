///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:49)

#ifndef RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H
#define RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Dx9Shader.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/VertexShader.h"

namespace Rendering
{
    class Dx9VertexShader : public Dx9Shader
    {
    public:
        using ClassType = Dx9VertexShader;
        using ParentType = Dx9Shader;

    public:
        Dx9VertexShader(Renderer* renderer, const VertexShader* vshader) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer, const VertexShader* vshader, const ShaderParameters* parameters) noexcept;
        void Disable(Renderer* renderer, const VertexShader* vshader, const ShaderParameters* parameters) noexcept;
    };

}

#endif  // RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H
