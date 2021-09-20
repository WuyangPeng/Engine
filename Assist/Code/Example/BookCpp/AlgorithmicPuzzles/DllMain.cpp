///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#include "Example/BookCpp/AlgorithmicPuzzles/AlgorithmicPuzzlesExport.h"

#include "AlgorithmicPuzzlesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ALGORITHMIC_PUZZLES_STATIC

DLL_MAIN_FUNCTION(AlgorithmicPuzzles);

#else  // BUILDING_ALGORITHMIC_PUZZLES_STATIC

CORE_TOOLS_MUTEX_INIT(AlgorithmicPuzzles);

#endif  // !BUILDING_ALGORITHMIC_PUZZLES_STATIC
