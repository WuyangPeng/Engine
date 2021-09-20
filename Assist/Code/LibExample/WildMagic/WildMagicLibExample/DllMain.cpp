// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 14:37)

#include "LibExample/WildMagic/WildMagicLibExample/WildMagicLibExampleExport.h"

#include "LibExample/WildMagic/WildMagicLibExample/WildMagicLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(WildMagicLibExample);

#else // !BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(WildMagicLibExample);

#endif // !BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC
