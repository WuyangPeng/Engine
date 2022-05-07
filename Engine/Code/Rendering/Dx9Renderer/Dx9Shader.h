///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/23 18:16)

#ifndef RENDERING_DX9_RENDERER_DX9_SHADER_H
#define RENDERING_DX9_RENDERER_DX9_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Dx9RendererData.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ShaderBase.h"
#include "Rendering/Shaders/ShaderParameters.h"

namespace Rendering
{
    class Dx9Shader
    {
    public:
        using ClassType = Dx9Shader;

    public:
        Dx9Shader() noexcept;
        virtual ~Dx9Shader() noexcept = default;
        Dx9Shader(const Dx9Shader& rhs) noexcept = default;
        Dx9Shader& operator=(const Dx9Shader& rhs) noexcept = default;
        Dx9Shader(Dx9Shader&& rhs) noexcept = default;
        Dx9Shader& operator=(Dx9Shader&& rhs) noexcept = default;
        ;
        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };

}

#endif  // RENDERING_DX9_RENDERER_DX9_SHADER_H
