///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/07 0:26)

#include "Example/BookCpp/AlgorithmsInCppParts1_4/AlgorithmsInCppParts1_4Export.h"

#include "AlgorithmsInCppParts1_4Fwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMS_IN_CPP_PARTS_1_4_STATIC

DLL_MAIN_FUNCTION(AlgorithmsInCppParts1_4);

#else  // BUILDING_ALGORITHMS_IN_CPP_PARTS_1_4_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmsInCppParts1_4);

#endif  // !BUILDING_ALGORITHMS_IN_CPP_PARTS_1_4_STATIC
