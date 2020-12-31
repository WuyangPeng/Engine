// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.4.0.0 (2020/07/15 14:43)

#include "Animation/AnimationExport.h"

#include "Animation/AnimationFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_STATIC

	DLL_MAIN_FUNCTION(Animation);

#else // !BUILDING_ANIMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(Animation);

#endif // !BUILDING_ANIMATION_STATIC