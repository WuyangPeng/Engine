///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/25 13:45)

#include "SoundEffect/SoundEffectExport.h"

#include "SoundEffect/SoundEffect.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SOUND_EFFECT_STATIC

namespace SoundEffect
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SOUND_EFFECT_STATIC
