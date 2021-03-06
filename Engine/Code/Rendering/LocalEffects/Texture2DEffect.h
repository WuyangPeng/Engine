// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 09:33)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Shaders/VisualEffectInstance.h" 

namespace Rendering
{
	class   Texture2DEffect : public VisualEffect
	{
	public:
		using ClassType = Texture2DEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Texture2DEffect);


	public:
		// Construction and destruction.
		Texture2DEffect ( ShaderFlags::SamplerFilter filter = ShaderFlags::SamplerFilter::Nearest,
						  ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
						  ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge );

 

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		// Create an instance of the effect with unique parameters.  If the
		// sampler filter mode is set to a value corresponding to mipmapping,
		// then the mipmaps will be generated if necessary.
		VisualEffectInstance* CreateInstance (Texture2D* texture) const;

		// Convenience for creating an instance.  The application does not have to
		// create the effect explicitly in order to create an instance from it.
		static VisualEffectInstance* CreateUniqueInstance (Texture2D* texture, ShaderFlags::SamplerFilter filter, 
														   ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1);

	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
	};
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(Texture2DEffect);
        CORE_TOOLS_SHARED_PTR_DECLARE(  Texture2DEffect);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_LOCAL_EFFECTS_TEXTURE2D_EFFECT_H
