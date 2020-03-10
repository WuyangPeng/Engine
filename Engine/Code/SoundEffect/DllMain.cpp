// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 14:32)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffect/SoundEffectFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

	DLL_MAIN_FUNCTION(SoundEffect);

#else // !BUILDING_SOUND_EFFECT_STATIC

	CORE_TOOLS_MUTEX_INIT(SoundEffect);

#endif // !BUILDING_SOUND_EFFECT_STATIC