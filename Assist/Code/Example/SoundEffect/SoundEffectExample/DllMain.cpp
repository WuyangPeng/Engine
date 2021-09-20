// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 21:34)

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleExport.h"

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(SoundEffectExample);

#else // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(SoundEffectExample);

#endif // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC
