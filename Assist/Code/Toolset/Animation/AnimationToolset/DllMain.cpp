///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/06/30 15:24)

#include "Toolset/Animation/AnimationToolset/AnimationToolsetExport.h"

#include "Toolset/Animation/AnimationToolset/AnimationToolsetFwd.h" 
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ANIMATION_STATIC

	DLL_MAIN_FUNCTION(Animation);

#else // !BUILDING_ANIMATION_STATIC

	CORE_TOOLS_MUTEX_INIT(Animation);

#endif // !BUILDING_ANIMATION_STATIC