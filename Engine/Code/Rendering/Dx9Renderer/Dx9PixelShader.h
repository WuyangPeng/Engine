///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 17:56)

#ifndef RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H
#define RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Dx9Shader.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/PixelShader.h"

namespace Rendering
{
    class Dx9PixelShader : public Dx9Shader
    {
    public:
        using ClassType = Dx9PixelShader;
        using ParentType = Dx9Shader;

    public:
        Dx9PixelShader(Renderer* renderer, const PixelShader* pshader) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters) noexcept;
        void Disable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters) noexcept;
    };
}

#endif  // RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H
