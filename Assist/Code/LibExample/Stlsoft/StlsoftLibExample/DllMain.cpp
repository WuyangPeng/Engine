// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 16:13)

#include "LibExample/Stlsoft/StlsoftLibExample/StlsoftLibExampleExport.h"

#include "LibExample/Stlsoft/StlsoftLibExample/StlsoftLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_STLSOFT_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(StlsoftLibExample);

#else // !BUILDING_STLSOFT_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(StlsoftLibExample);

#endif // !BUILDING_STLSOFT_LIB_EXAMPLE_STATIC
