///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/03 14:45)

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
