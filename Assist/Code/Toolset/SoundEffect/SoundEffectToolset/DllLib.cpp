///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/09 19:21)

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
