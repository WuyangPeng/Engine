// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:17)

#include "LibExample/Freetype/FreetypeLibExample/FreetypeLibExampleExport.h"

#include "LibExample/Freetype/FreetypeLibExample/FreetypeLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FREETYPE_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(FreetypeLibExample);

#else // !BUILDING_FREETYPE_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(FreetypeLibExample);

#endif // !BUILDING_FREETYPE_LIB_EXAMPLE_STATIC
