// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/23 23:18)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "Example/Network/NetworkExample/NetworkExample.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_EXAMPLE_STATIC

namespace NetworkExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_EXAMPLE_STATIC
