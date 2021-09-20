// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/10 23:28)

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetExport.h"

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

	DLL_MAIN_FUNCTION(AssistTools);

#else // !BUILDING_ASSIST_TOOLS_STATIC

	CORE_TOOLS_MUTEX_INIT(AssistTools);

#endif // !BUILDING_ASSIST_TOOLS_STATIC
