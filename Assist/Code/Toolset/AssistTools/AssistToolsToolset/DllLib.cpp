// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/10 23:28)

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetExport.h"

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "AssistTools/AssistToolsLib.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

    #include "DllLib.h"

#else  // BUILDING_ASSIST_TOOLS_STATIC

namespace AssistToolsToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ASSIST_TOOLS_STATIC