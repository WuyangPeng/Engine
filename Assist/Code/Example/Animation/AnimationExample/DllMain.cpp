///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 16:00)

#include "Example/Animation/AnimationExample/AnimationExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Animation/AnimationExample/AnimationExampleFwd.h"

#ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(AnimationExample);

#else  // !BUILDING_ANIMATION_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(AnimationExample);

#endif  // !BUILDING_ANIMATION_EXAMPLE_STATIC
