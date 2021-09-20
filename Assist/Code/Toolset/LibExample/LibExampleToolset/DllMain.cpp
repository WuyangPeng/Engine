// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 1:46)

#include "Toolset/LibExample/LibExampleToolset/LibExampleToolsetExport.h"

#include "Toolset/LibExample/LibExampleToolset/LibExampleToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(LibExample);

#else // !BUILDING_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(LibExample);

#endif // !BUILDING_LIB_EXAMPLE_STATIC
