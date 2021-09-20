// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 19:14)

#include "Example/Imagics/ImagicsExample/ImagicsExampleExport.h"

#include "Example/Imagics/ImagicsExample/ImagicsExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ImagicsExample);

#else // !BUILDING_IMAGICS_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ImagicsExample);

#endif // !BUILDING_IMAGICS_EXAMPLE_STATIC
