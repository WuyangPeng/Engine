// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 22:44)

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolsetExport.h"

#include "Toolset/Imagics/ImagicsToolset/ImagicsToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Imagics/ImagicsLib.h"

#ifndef BUILDING_IMAGICS_STATIC

    #include "DllLib.h"

#else  // BUILDING_IMAGICS_STATIC

namespace ImagicsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_IMAGICS_STATIC
