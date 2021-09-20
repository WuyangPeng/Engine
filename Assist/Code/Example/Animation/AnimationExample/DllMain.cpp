// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 20:22)

#include "Example/Animation/AnimationExample/AnimationExampleExport.h"

#include "Example/Animation/AnimationExample/AnimationExampleFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

	DLL_MAIN_FUNCTION(AnimationExample);

#else // !BUILDING_ANIMATION_EXAMPLE_STATIC

	CORE_TOOLS_MUTEX_INIT(AnimationExample);

#endif // !BUILDING_ANIMATION_EXAMPLE_STATIC
