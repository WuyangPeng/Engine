// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 21:34)

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExampleExport.h"

#include "Example/SoundEffect/SoundEffectExample/SoundEffectExample.h"

#include "CoreTools/CoreToolsLib.h"

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
