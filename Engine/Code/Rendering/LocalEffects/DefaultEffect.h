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
		virtual ~DefaultEffect ();
		
		// Create an instance of the effect with unique parameters.
		VisualEffectInstance* CreateInstance () const;
		
	private:
		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[ShaderFlags::MaxProfiles];
		static std::string msVPrograms[ShaderFlags::MaxProfiles];
		static std::string msPPrograms[ShaderFlags::MaxProfiles];
	};

	CORE_TOOLS_STREAM_REGISTER(DefaultEffect);
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, DefaultEffect);
}

#endif // RENDERING_LOCAL_EFFECTS_DEFAULT_EFFECT_H
