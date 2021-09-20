///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/03/28 12:57)

#include "Example/BookCpp/AlgorithmicPuzzles/AlgorithmicPuzzlesExport.h"

#include "AlgorithmicPuzzlesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMIC_PUZZLES_STATIC

DLL_MAIN_FUNCTION(AlgorithmicPuzzles);

#else  // BUILDING_ALGORITHMIC_PUZZLES_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmicPuzzles);

#endif  // !BUILDING_ALGORITHMIC_PUZZLES_STATIC
