// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 14:59)

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleExport.h"

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(AssistToolsExample);

#else // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(AssistToolsExample);

#endif // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC
