// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 09:32)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Shaders/VisualEffectInstance.h" 

namespace Rendering
{
	class Texture2ColorBlendEffect : public VisualEffect
	{
	public:
		using ClassType = Texture2ColorBlendEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2ColorBlendEffect);
		
	public:
		// Construction and destruction.
		Texture2ColorBlendEffect (); 

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		// Create an instance of the effect with unique parameters.  If a
		// sampler filter mode is set to a value corresponding to mipmapping,
		// then the mipmaps will be generated if necessary.
		VisualEffectInstance* CreateInstance (Texture2D* texture0,Texture2D* texture1) const;

		// Convenience for creating an instance.  The application does not have to
		// create the effect explicitly in order to create an instance from it.
		static VisualEffectInstance* CreateUniqueInstance (Texture2D* texture0,ShaderFlags::SamplerFilter filter0,ShaderFlags::SamplerCoordinate coordinate00,
														   ShaderFlags::SamplerCoordinate coordinate01,Texture2D* texture1,ShaderFlags::SamplerFilter filter1,
														   ShaderFlags::SamplerCoordinate coordinate10,ShaderFlags::SamplerCoordinate coordinate11);

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static int msAllPTextureUnits[2];
		static int* msPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
	};
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
 
	CORE_TOOLS_STREAM_REGISTER(Texture2ColorBlendEffect);
	CORE_TOOLS_SHARED_PTR_DECLARE( Texture2ColorBlendEffect);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_LOCAL_EFFECTS_TEXTURE2_COLOR_BLEND_EFFECT_H
