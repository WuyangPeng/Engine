///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/DataStructuresAndAlgorithmsInCpp/DataStructuresAndAlgorithmsInCppExport.h"

#include "DataStructuresAndAlgorithmsInCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC

DLL_MAIN_FUNCTION(DataStructuresAndAlgorithmsInCpp);

#else  // BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(DataStructuresAndAlgorithmsInCpp);

#endif  // !BUILDING_DATA_STRUCTURES_AND_ALGORITHMS_IN_CPP_STATIC
