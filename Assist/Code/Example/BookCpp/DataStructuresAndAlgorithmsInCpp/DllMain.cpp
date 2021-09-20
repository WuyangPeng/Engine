///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/DataStructuresAndAlgorithmsInCpp/DataStructuresAndAlgorithmsInCppExport.h"

#include "DataStructuresAndAlgorithmsInCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC

DLL_MAIN_FUNCTION(DataStructuresAndAlgorithmsInCpp);

#else  // BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(DataStructuresAndAlgorithmsInCpp);

#endif  // !BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC
