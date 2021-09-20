// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 19:24)

#include "Example/Mathematics/MathematicsExample/MathematicsExampleExport.h"

#include "Example/Mathematics/MathematicsExample/MathematicsExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MATHEMATICS_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(MathematicsExample);

#else // !BUILDING_MATHEMATICS_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(MathematicsExample);

#endif // !BUILDING_MATHEMATICS_EXAMPLE_STATIC
