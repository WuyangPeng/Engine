// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 1:15)

#include "Example/ArtificialIntellegence/ArtificialIntellegenceExample/ArtificialIntellegenceExampleExport.h"

#include "Example/ArtificialIntellegence/ArtificialIntellegenceExample/ArtificialIntellegenceExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(ArtificialIntellegenceExample);

#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(ArtificialIntellegenceExample);

#endif // !BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC
