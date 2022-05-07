// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 19:14)

#include "Example/Imagics/ImagicsExample/ImagicsExampleExport.h"

#include "Example/Imagics/ImagicsExample/ImagicsExample.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_IMAGICS_EXAMPLE_STATIC

namespace ImagicsExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_IMAGICS_EXAMPLE_STATIC
