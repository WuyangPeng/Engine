// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/24 0:15)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "Example/Database/DatabaseExample/DatabaseExample.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_EXAMPLE_STATIC

namespace DatabaseExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_EXAMPLE_STATIC
