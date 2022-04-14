///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/25 13:45)

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
