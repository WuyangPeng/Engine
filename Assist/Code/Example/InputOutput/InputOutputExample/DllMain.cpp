// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 22:54)

#include "Example/InputOutput/InputOutputExample/InputOutputExampleExport.h"

#include "Example/InputOutput/InputOutputExample/InputOutputExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(InputOutputExample);

#else // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(InputOutputExample);

#endif // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC
