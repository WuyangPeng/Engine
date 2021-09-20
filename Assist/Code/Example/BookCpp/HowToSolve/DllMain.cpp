///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/HowToSolve/HowToSolveExport.h"

#include "HowToSolveFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_HOW_TO_SOLVE_STATIC

DLL_MAIN_FUNCTION(HowToSolve);

#else  // BUILDING_HOW_TO_SOLVE_STATIC

CORE_TOOLS_MUTEX_INIT(HowToSolve);

#endif  // !BUILDING_HOW_TO_SOLVE_STATIC
