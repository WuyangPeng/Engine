///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/30 21:53)

#include "Example/BookCpp/ThrivingInACrowdedAndChangingWorld/ThrivingInACrowdedAndChangingWorldExport.h"

#include "ThrivingInACrowdedAndChangingWorldFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

DLL_MAIN_FUNCTION(ThrivingInACrowdedAndChangingWorld);

#else  // BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC

CORE_TOOLS_MUTEX_INIT(ThrivingInACrowdedAndChangingWorld);

#endif  // !BUILDING_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_STATIC
