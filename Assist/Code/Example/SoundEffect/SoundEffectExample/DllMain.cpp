///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/09 19:25)

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleFwd.h"

#ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(SoundEffectExample);

#else  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(SoundEffectExample);

#endif  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC
