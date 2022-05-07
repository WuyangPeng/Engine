///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 13:39)

#ifndef RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformShaderImpl
    {
    public:
        using ClassType = PlatformShaderImpl;
        using PlatformShaderPtr = std::shared_ptr<ClassType>;

    public:
        PlatformShaderImpl() noexcept;
        virtual ~PlatformShaderImpl() noexcept = default;
        PlatformShaderImpl(const PlatformShaderImpl& rhs) noexcept = default;
        PlatformShaderImpl& operator=(const PlatformShaderImpl& rhs) noexcept = default;
        PlatformShaderImpl(PlatformShaderImpl&& rhs) noexcept = default;
        PlatformShaderImpl& operator=(PlatformShaderImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        virtual void SetSamplerState(Renderer* renderer, const ShaderBase* shader, int profile, const ShaderParameters* parameters, int maxSamplers, const SamplerState* currentSamplerState) = 0;

        virtual void DisableTextures(Renderer* renderer, const ShaderBase* shader, int profile, const ShaderParameters* parameters, int maxSamplers) = 0;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H
