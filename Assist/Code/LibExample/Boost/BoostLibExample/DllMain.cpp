// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 10:36)

#include "LibExample/Boost/BoostLibExample/BoostLibExampleExport.h"

#include "LibExample/Boost/BoostLibExample/BoostLibExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BOOST_LIB_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(BoostLibExample);

#else // !BUILDING_BOOST_LIB_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(BoostLibExample);

#endif // !BUILDING_BOOST_LIB_EXAMPLE_STATIC
