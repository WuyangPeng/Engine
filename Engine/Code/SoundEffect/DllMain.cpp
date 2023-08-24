///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/03 14:45)

#include "SoundEffect/SoundEffectExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "SoundEffect/SoundEffectFwd.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

DLL_MAIN_FUNCTION(SoundEffect);

#else  // !BUILDING_SOUND_EFFECT_STATIC

CORE_TOOLS_MUTEX_INIT(SoundEffect);

#endif  // !BUILDING_SOUND_EFFECT_STATIC