// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:40)

#ifndef RENDERING_SHADERS_SHADER_MANAGE_IMPL_H
#define RENDERING_SHADERS_SHADER_MANAGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderManagerImpl
    {
    public:
        using ClassType = ShaderManagerImpl;
        using VertexShaderProfile = ShaderFlags::VertexShaderProfile;
        using PixelShaderProfile = ShaderFlags::PixelShaderProfile;

    public:
        ShaderManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetVertexProfile(VertexShaderProfile profile) noexcept;
        VertexShaderProfile GetVertexProfile() const noexcept;

        void SetPixelProfile(PixelShaderProfile profile) noexcept;
        PixelShaderProfile GetPixelProfile() const noexcept;

    private:
        VertexShaderProfile m_VertexShaderProfile;
        PixelShaderProfile m_PixelShaderProfile;
    };
}

#endif  // RENDERING_SHADERS_SHADER_MANAGE_IMPL_H
