// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/16 14:32)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffect/SoundEffectFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

	DLL_MAIN_FUNCTION(SoundEffect);

#else // !BUILDING_SOUND_EFFECT_STATIC

	CORE_TOOLS_MUTEX_INIT(SoundEffect);

#endif // !BUILDING_SOUND_EFFECT_STATIC