// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.3.0 (2020/03/24 23:22)

#include "Example/BookSoftwareDesign/DesignPatternsExplained/DesignPatternsExplainedExport.h"

#include "DesignPatternsExplainedFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h" 

#ifndef BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC

	DLL_MAIN_FUNCTION(DesignPatternsExplained);

#else // !BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC

	CORE_TOOLS_MUTEX_INIT(DesignPatternsExplained);

#endif // BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC
