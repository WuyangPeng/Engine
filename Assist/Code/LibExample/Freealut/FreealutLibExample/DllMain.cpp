// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:28)

#include "LibExample/Freealut/FreealutLibExample/FreealutLibExampleExport.h"

#include "LibExample/Freealut/FreealutLibExample/FreealutLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FREEALUT_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(FreealutLibExample);

#else // !BUILDING_FREEALUT_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(FreealutLibExample);

#endif // !BUILDING_FREEALUT_LIB_EXAMPLE_STATIC
