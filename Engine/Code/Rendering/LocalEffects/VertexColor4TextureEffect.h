// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 09:40)

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

		virtual ~VertexColor4TextureEffect ();

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
		static int* msVRegisters[ShaderFlags::MaxProfiles];
		static std::string msVPrograms[ShaderFlags::MaxProfiles];
		static int msAllPTextureUnits[1];
		static int* msPTextureUnits[ShaderFlags::MaxProfiles];
		static std::string msPPrograms[ShaderFlags::MaxProfiles];
	};
 
	CORE_TOOLS_STREAM_REGISTER(VertexColor4TextureEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, VertexColor4TextureEffect);
}

#endif // RENDERING_LOCAL_EFFECTS_VERTEX_COLOR4_TEXTUR_EEFFECT_H
