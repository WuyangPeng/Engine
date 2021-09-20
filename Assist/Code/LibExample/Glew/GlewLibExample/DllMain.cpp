// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 0:19)

#include "LibExample/Glew/GlewLibExample/GlewLibExampleExport.h"

#include "LibExample/Glew/GlewLibExample/GlewLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GLEW_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(GlewLibExample);

#else // !BUILDING_GLEW_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(GlewLibExample);

#endif // !BUILDING_GLEW_LIB_EXAMPLE_STATIC
