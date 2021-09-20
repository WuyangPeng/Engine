// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.3 (2020/05/01 14:08)

#include "Example/Framework/FrameworkExample/FrameworkExampleExport.h"

#include "Example/Framework/FrameworkExample/FrameworkExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(FrameworkExample);

#else // !BUILDING_FRAMEWORK_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(FrameworkExample);

#endif // !BUILDING_FRAMEWORK_EXAMPLE_STATIC
