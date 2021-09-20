///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#include "Example/BookCpp/AlgorithmsUnlocked/AlgorithmsUnlockedExport.h"

#include "AlgorithmsUnlockedFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMS_UNLOCKED_STATIC

DLL_MAIN_FUNCTION(AlgorithmsUnlocked);

#else  // BUILDING_ALGORITHMS_UNLOCKED_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmsUnlocked);

#endif  // !BUILDING_ALGORITHMS_UNLOCKED_STATIC
