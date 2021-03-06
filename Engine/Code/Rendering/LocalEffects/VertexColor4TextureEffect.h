// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 09:40)

#ifndef RENDERING_LOCAL_EFFECTS_VERTEX_COLOR4_TEXTUR_EEFFECT_H
#define RENDERING_LOCAL_EFFECTS_VERTEX_COLOR4_TEXTUR_EEFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VisualEffectInstance.h" 
#include "Rendering/Resources/Texture2D.h"

namespace Rendering
{
	class   VertexColor4TextureEffect : public VisualEffect
	{
	public:
		using ClassType = VertexColor4TextureEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VertexColor4TextureEffect);

	public:
		// Construction and destruction.
		VertexColor4TextureEffect (ShaderFlags::SamplerFilter filter = ShaderFlags::SamplerFilter::Nearest,
								   ShaderFlags::SamplerCoordinate coordinate0 = ShaderFlags::SamplerCoordinate::ClampEdge,
								   ShaderFlags::SamplerCoordinate coordinate1 = ShaderFlags::SamplerCoordinate::ClampEdge);

 

		// Any change in sampler state is made via the pixel shader.
		PixelShader* GetPixelShader () const;

		// Create an instance of the effect with unique parameters.  If the
		// sampler filter mode is set to a value corresponding to mipmapping,
		// then the mipmaps will be generated if necessary.
		VisualEffectInstance* CreateInstance (Texture2D* texture) const;

		// Convenience for creating an instance.  The application does not have to
		// create the effect explicitly in order to create an instance from it.
		static VisualEffectInstance* CreateUniqueInstance (Texture2D* texture, ShaderFlags::SamplerFilter filter, ShaderFlags::SamplerCoordinate coordinate0, ShaderFlags::SamplerCoordinate coordinate1);

	protected:
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
	CORE_TOOLS_STREAM_REGISTER(VertexColor4TextureEffect);
	CORE_TOOLS_SHARED_PTR_DECLARE( VertexColor4TextureEffect);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_LOCAL_EFFECTS_VERTEX_COLOR4_TEXTUR_EEFFECT_H
