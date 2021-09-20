// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 18:59)

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolsetExport.h"

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

	DLL_MAIN_FUNCTION(SoundEffect);

#else // !BUILDING_SOUND_EFFECT_STATIC

	CORE_TOOLS_MUTEX_INIT(SoundEffect);

#endif // !BUILDING_SOUND_EFFECT_STATIC
