///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:25)

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolsetExport.h"

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolset.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SOUND_EFFECT_STATIC

namespace SoundEffectToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SOUND_EFFECT_STATIC
