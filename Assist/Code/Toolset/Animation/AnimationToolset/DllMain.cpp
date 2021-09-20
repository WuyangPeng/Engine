// Copyright (c) 2011-2020
// Threading Core Render Engine
// „ч’я£Ї≈нќд—ф£ђ≈нк ґч£ђ≈нк ‘у
//
// “э«жЄ®÷ъ∞ж±Њ£Ї0.0.2.0 (2020/01/07 23:00)

#include "Toolset/Animation/AnimationToolset/AnimationToolsetExport.h"

#include "Toolset/Animation/AnimationToolset/AnimationToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_STATIC

	DLL_MAIN_FUNCTION(Animation);

#else // !BUILDING_ANIMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(Animation);

#endif // !BUILDING_ANIMATION_STATIC