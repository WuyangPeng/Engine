// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 09:30)

#ifndef RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/VisualEffectInstance.h" 

namespace Rendering
{
	class MaterialTextureEffect : public VisualEffect
	{
	public:
		using ClassType = MaterialTextureEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MaterialTextureEffect);


	public:
		// Construction and destruction.
		MaterialTextureEffect(ShaderFlags::SamplerFilter filter = ShaderFlags::SamplerFilter::Nearest,
							  ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
							  ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge);

		virtual ~MaterialTextureEffect ();

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		// Create an instance of the effect with unique parameters.  If the
		// sampler filter mode is set to a value corresponding to mipmapping,
		// then the mipmaps will be generated if necessary.
		VisualEffectInstance* CreateInstance (Material* material, Texture2D* texture) const;

		// Convenience for creating an instance.  The application does not have to
		// create the effect explicitly in order to create an instance from it.
		static VisualEffectInstance* CreateUniqueInstance (Material* material, Texture2D* texture, ShaderFlags::SamplerFilter filter,
														   ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1);

	private:
		static int msDx9VRegisters[2];
		static int msOglVRegisters[2];
		static int* msVRegisters[ShaderFlags::MaxProfiles];
		static std::string msVPrograms[ShaderFlags::MaxProfiles];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[ShaderFlags::MaxProfiles];
		static std::string msPPrograms[ShaderFlags::MaxProfiles];
	};

 
	CORE_TOOLS_STREAM_REGISTER(MaterialTextureEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, MaterialTextureEffect);
}

#endif // RENDERING_LOCAL_EFFECTS_MATERIAL_TEXTURE_EFFECT_H
