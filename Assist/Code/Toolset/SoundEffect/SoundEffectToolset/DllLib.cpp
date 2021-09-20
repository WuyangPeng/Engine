// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 18:59)

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolsetExport.h"

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "SoundEffect/SoundEffectLib.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

	#include "DllLib.h"

#else // BUILDING_SOUND_EFFECT_STATIC

	namespace SoundEffectToolset
	{
		void StaticDllLib()
		{

		}
	}

#endif // !BUILDING_SOUND_EFFECT_STATIC
