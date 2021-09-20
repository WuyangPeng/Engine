// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:32)

#include "LibExample/Openal/OpenalLibExample/OpenalLibExampleExport.h"

#include "LibExample/Openal/OpenalLibExample/OpenalLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OPENAL_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(OpenalLibExample);

#else // !BUILDING_OPENAL_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(OpenalLibExample);

#endif // !BUILDING_OPENAL_LIB_EXAMPLE_STATIC
