///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H
#define RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Flags/TextureFlags.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Resources/Textures/TextureCube.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    template <typename TextureFlags>
    struct TextureDataTraits;

    template <>
    struct TextureDataTraits<Texture1D>
    {
        static constexpr auto dimension = 1;
        static constexpr auto face = 1;
        static constexpr auto samplerType = ShaderFlags::SamplerType::Sampler1D;
        static constexpr auto textureTargetType = System::TextureTarget::Texture1D;
        static constexpr auto textureType = TextureFlags::Texture1D;
    };

    template <>
    struct TextureDataTraits<Texture2D>
    {
        static constexpr auto dimension = 2;
        static constexpr auto face = 1;
        static constexpr auto samplerType = ShaderFlags::SamplerType::Sampler2D;
        static constexpr auto textureTargetType = System::TextureTarget::Texture2D;
        static constexpr auto textureType = TextureFlags::Texture2D;
    };

    template <>
    struct TextureDataTraits<Texture3D>
    {
        static constexpr auto dimension = 3;
        static constexpr auto face = 1;
        static constexpr auto samplerType = ShaderFlags::SamplerType::Sampler3D;
        static constexpr auto textureTargetType = System::TextureTarget::Texture3D;
        static constexpr auto textureType = TextureFlags::Texture3D;
    };

    template <>
    struct TextureDataTraits<TextureCube>
    {
        static constexpr auto dimension = 2;
        static constexpr auto face = 6;
        static constexpr auto samplerType = ShaderFlags::SamplerType::SamplerCube;
        static constexpr auto textureTargetType = System::TextureTarget::TextureCubeMap;
        static constexpr auto textureType = TextureFlags::TextureCube;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H
