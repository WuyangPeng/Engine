// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 22:07)

#include "LibExample/GeometricTools/GeometricToolsLibExample/GeometricToolsLibExampleExport.h"

#include "LibExample/GeometricTools/GeometricToolsLibExample/GeometricToolsLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(GeometricToolsLibExample);

#else // !BUILDING_GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(GeometricToolsLibExample);

#endif // !BUILDING_GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC
