///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/PracticalAlgorithmsForProgrammers/PracticalAlgorithmsForProgrammersExport.h"

#include "PracticalAlgorithmsForProgrammersFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

DLL_MAIN_FUNCTION(PracticalAlgorithmsForProgrammers);

#else  // BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC

CORE_TOOLS_MUTEX_INIT(PracticalAlgorithmsForProgrammers);

#endif  // !BUILDING_PRACTICAL_ALGORITHMS_FOR_PROGRAMMERS_STATIC
