// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 12:51)

#include "LibExample/Freeglut/FreeglutLibExample/FreeglutLibExampleExport.h"

#include "LibExample/Freeglut/FreeglutLibExample/FreeglutLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(FreeglutLibExample);

#else // !BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(FreeglutLibExample);

#endif // !BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC
