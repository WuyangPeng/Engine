// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:20)

#ifndef RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include <memory>

namespace Rendering
{
    class Renderer;
    class ShaderBase;
    class ShaderParameters;
    class SamplerState;

    class RENDERING_HIDDEN_DECLARE PlatformShaderImpl
    {
    public:
        typedef PlatformShaderImpl ClassType;
        typedef std::shared_ptr<ClassType> PlatformShaderPtr;

    public:
        PlatformShaderImpl() noexcept;
        virtual ~PlatformShaderImpl();
        PlatformShaderImpl(const PlatformShaderImpl&) = default;
        PlatformShaderImpl& operator=(const PlatformShaderImpl&) = default;
        PlatformShaderImpl(PlatformShaderImpl&&) = default;
        PlatformShaderImpl& operator=(PlatformShaderImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        virtual void SetSamplerState(Renderer* renderer, const ShaderBase* shader, int profile, const ShaderParameters* parameters, int maxSamplers, const SamplerState* currentSamplerState) = 0;

        virtual void DisableTextures(Renderer* renderer, const ShaderBase* shader, int profile, const ShaderParameters* parameters, int maxSamplers) = 0;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_SHADER_IMPL_H
