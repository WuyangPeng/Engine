// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 22:54)

#include "Example/InputOutput/InputOutputExample/InputOutputExampleExport.h"

#include "Example/InputOutput/InputOutputExample/InputOutputExample.h"

#include "CoreTools/CoreToolsLib.h"

#ifndef BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

namespace InputOutputExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC
