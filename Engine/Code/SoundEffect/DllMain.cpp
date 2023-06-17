///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 19:15)

#include "SoundEffect/SoundEffectExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "SoundEffect/SoundEffectFwd.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

DLL_MAIN_FUNCTION(SoundEffect);

#else  // !BUILDING_SOUND_EFFECT_STATIC

CORE_TOOLS_MUTEX_INIT(SoundEffect);

#endif  // !BUILDING_SOUND_EFFECT_STATIC