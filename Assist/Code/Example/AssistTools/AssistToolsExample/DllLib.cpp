// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 14:59)

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleExport.h"

#include "Example/AssistTools/AssistToolsExample/AssistToolsExample.h"

#ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

namespace AssistToolsExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC
