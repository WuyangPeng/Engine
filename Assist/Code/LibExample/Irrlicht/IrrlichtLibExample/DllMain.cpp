// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:16)

#include "LibExample/Irrlicht/IrrlichtLibExample/IrrlichtLibExampleExport.h"

#include "LibExample/Irrlicht/IrrlichtLibExample/IrrlichtLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(IrrlichtLibExample);

#else // !BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(IrrlichtLibExample);

#endif // !BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC
