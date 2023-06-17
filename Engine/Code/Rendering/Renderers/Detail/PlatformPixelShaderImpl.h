///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "PlatformShaderImpl.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformPixelShaderImpl
    {
    public:
        using ClassType = PlatformPixelShaderImpl;
        using PlatformPixelShaderPtr = std::shared_ptr<ClassType>;

    public:
        PlatformPixelShaderImpl() noexcept;
        virtual ~PlatformPixelShaderImpl() noexcept = default;
        PlatformPixelShaderImpl(const PlatformPixelShaderImpl& rhs) noexcept = default;
        PlatformPixelShaderImpl& operator=(const PlatformPixelShaderImpl& rhs) noexcept = default;
        PlatformPixelShaderImpl(PlatformPixelShaderImpl&& rhs) noexcept = default;
        PlatformPixelShaderImpl& operator=(PlatformPixelShaderImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Enable(Renderer* renderer, const PixelShader* pixelShader, const ShaderParameters* parameters) = 0;
        virtual void Disable(Renderer* renderer, const PixelShader* pixelShader, const ShaderParameters* parameters) = 0;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H
