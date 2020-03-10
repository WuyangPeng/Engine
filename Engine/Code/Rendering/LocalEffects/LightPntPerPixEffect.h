// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 18:09)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_PNT_PER_PIX_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_PNT_PER_PIX_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/SceneGraph/Light.h"
#include "Rendering/SceneGraph/Material.h"
#include "Rendering/Shaders/VisualEffectInstance.h" 

namespace Rendering
{
	class  LightPntPerPixEffect : public VisualEffect
	{
	public:
		using ClassType = LightPntPerPixEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(LightPntPerPixEffect);
		
	public:
		// Construction and destruction.
		LightPntPerPixEffect ();
		virtual ~LightPntPerPixEffect ();
		
		// Create an instance of the effect with unique parameters.
		VisualEffectInstance* CreateInstance (Light* light,   Material* material) const;
		
		// Convenience for creating an instance.  The application does not have to
		// create the effect explicitly in order to create an instance from it.
		static VisualEffectInstance* CreateUniqueInstance (Light* light,   Material* material);
		
	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[ShaderFlags::MaxProfiles];
		static std::string msVPrograms[ShaderFlags::MaxProfiles];
		static int msAllPRegisters[11];
		static int* msPRegisters[ShaderFlags::MaxProfiles];
		static std::string msPPrograms[ShaderFlags::MaxProfiles];
	};

	CORE_TOOLS_STREAM_REGISTER(LightPntPerPixEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, LightPntPerPixEffect);

}

#endif // RENDERING_LOCAL_EFFECTS_LIGHT_PNT_PER_PIX_EFFECT_H
