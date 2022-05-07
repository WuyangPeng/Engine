// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 20:20)

#include "Example/Animation/AnimationExample/AnimationExampleExport.h"

#include "Example/Animation/AnimationExample/AnimationExample.h"

#include "System/SystemLib.h"
#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ANIMATION_EXAMPLE_STATIC

namespace AnimationExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ANIMATION_EXAMPLE_STATIC
