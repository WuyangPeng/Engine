///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/30 21:53)

#include "Example/BookCpp/ThrivingInACrowdedAndChangingWorld/ThrivingInACrowdedAndChangingWorldExport.h"

#include "ThrivingInACrowdedAndChangingWorldFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

DLL_MAIN_FUNCTION(ThrivingInACrowdedAndChangingWorld);

#else  // BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

CORE_TOOLS_MUTEX_INIT(ThrivingInACrowdedAndChangingWorld);

#endif  // !BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC
