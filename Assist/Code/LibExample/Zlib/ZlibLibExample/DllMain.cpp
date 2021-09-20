// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:09)

#include "LibExample/Zlib/ZlibLibExample/ZlibLibExampleExport.h"

#include "LibExample/Zlib/ZlibLibExample/ZlibLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ZLIB_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ZlibLibExample);

#else // !BUILDING_ZLIB_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ZlibLibExample);

#endif // !BUILDING_ZLIB_LIB_EXAMPLE_STATIC
