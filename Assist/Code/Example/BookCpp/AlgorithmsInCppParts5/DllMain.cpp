///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/07 0:26)

#include "Example/BookCpp/AlgorithmsInCppParts5/AlgorithmsInCppParts5Export.h"

#include "AlgorithmsInCppParts5Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC

DLL_MAIN_FUNCTION(AlgorithmsInCppParts5);

#else  // BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmsInCppParts5);

#endif  // !BUILDING_ALGORITHMS_IN_CPP_PARTS_5_STATIC
