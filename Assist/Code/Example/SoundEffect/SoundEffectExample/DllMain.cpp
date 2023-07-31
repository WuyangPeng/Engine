///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:54)

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleFwd.h"

#ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(SoundEffectExample);

#else  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(SoundEffectExample);

#endif  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC
