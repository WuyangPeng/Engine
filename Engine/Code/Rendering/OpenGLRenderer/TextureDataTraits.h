// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:14)

#ifndef RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H
#define RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/Resources/Flags/TextureFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{	
	template <typename TextureFlags>
	struct TextureDataTraits;

	template <>
	struct TextureDataTraits<Texture1D>
	{
		static constexpr int sm_Dimension = 1;
		static constexpr int sm_Face = 1;
		static constexpr ShaderFlags::SamplerType sm_SamplerType = ShaderFlags::SamplerType::Sampler1D;
		static constexpr System::TextureTarget sm_TextureTargetType = System::TextureTarget::Texture1D;
		static constexpr TextureFlags sm_TextureType = TextureFlags::Texture1D;
	};

	template <>
	struct TextureDataTraits<Texture2D>
	{
		static constexpr int sm_Dimension = 2;
		static constexpr int sm_Face = 1;
		static constexpr ShaderFlags::SamplerType sm_SamplerType = ShaderFlags::SamplerType::Sampler2D;
		static constexpr System::TextureTarget sm_TextureTargetType = System::TextureTarget::Texture2D;
		static constexpr TextureFlags sm_TextureType = TextureFlags::Texture2D;
	};  

	template <>
	struct TextureDataTraits<Texture3D>
	{
		static constexpr int sm_Dimension = 3;
		static constexpr int sm_Face = 1;
		static constexpr ShaderFlags::SamplerType sm_SamplerType = ShaderFlags::SamplerType::Sampler3D;
		static constexpr System::TextureTarget sm_TextureTargetType = System::TextureTarget::Texture3D;
		static constexpr TextureFlags sm_TextureType = TextureFlags::Texture3D;
	};  

	template <>
	struct TextureDataTraits<TextureCube>
	{
		static constexpr int sm_Dimension = 2;
		static constexpr int sm_Face = 6;
		static constexpr ShaderFlags::SamplerType sm_SamplerType = ShaderFlags::SamplerType::SamplerCube;
		static constexpr System::TextureTarget sm_TextureTargetType = System::TextureTarget::TextureCubeMap;
		static constexpr TextureFlags sm_TextureType = TextureFlags::TextureCube;
	};   
}

#endif // RENDERING_OPENGL_RENDERER_TEXTURE_DATA_TRAITS_H
