///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/12 18:23)

#include "Example/Animation/AnimationExample/AnimationExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Animation/AnimationExample/AnimationExampleFwd.h"

#ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(AnimationExample);

#else  // !BUILDING_ANIMATION_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(AnimationExample);

#endif  // !BUILDING_ANIMATION_EXAMPLE_STATIC
