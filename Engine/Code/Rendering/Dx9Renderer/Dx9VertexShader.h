///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 21:31)

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
