///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/PracticalAlgorithmsForProgrammers/PracticalAlgorithmsForProgrammersExport.h"

#include "PracticalAlgorithmsForProgrammersFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

DLL_MAIN_FUNCTION(PracticalAlgorithmsForProgrammers);

#else  // BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

CORE_TOOLS_MUTEX_INIT(PracticalAlgorithmsForProgrammers);

#endif  // !BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC
