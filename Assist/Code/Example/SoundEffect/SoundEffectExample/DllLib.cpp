///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/09 19:25)

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleExport.h"

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExample.h"

#ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

namespace SoundEffectExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC
