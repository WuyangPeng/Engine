// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/08 21:29)

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetExport.h"

#include "Toolset/ArtificialIntellegence/ArtificialIntellegenceToolset/ArtificialIntellegenceToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	DLL_MAIN_FUNCTION(ArtificialIntellegence);

#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC

	CORE_TOOLS_MUTEX_INIT(ArtificialIntellegence);

#endif // !BUILDING_ARTIFICIAL_INTELLEGENCE_STATIC
