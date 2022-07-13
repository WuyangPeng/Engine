///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 16:52)

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolsetExport.h"

#include "Toolset/SoundEffect/SoundEffectToolset/SoundEffectToolset.h"

#ifndef BUILDING_SOUND_EFFECT_STATIC

    #include "DllLib.h"

#else  // BUILDING_SOUND_EFFECT_STATIC

namespace SoundEffectToolset
{
    void StaticDllLib()
    {
    }
}

#endif  // !BUILDING_SOUND_EFFECT_STATIC
