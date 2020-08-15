// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 18:07)

#ifndef RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H
#define RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VisualEffectInstance.h"

namespace Rendering
{
	class DefaultEffect : public VisualEffect
	{
	public:
		using ClassType = DefaultEffect;
		using ParentType = VisualEffect;

	private:
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DefaultEffect);
		
	public:
		// Construction and destruction.
		DefaultEffect ();
 
		
		// Create an instance of the effect with unique parameters.
		VisualEffectInstance* CreateInstance () const;
		
	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msVPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
		static std::string msPPrograms[System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles)];
	};
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(DefaultEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, DefaultEffect);
	#include STSTEM_WARNING_POP
}

#endif // RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H
