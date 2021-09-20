///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/13 23:17)

#include "Example/BookCpp/OptimizedCpp/OptimizedCppExport.h"

#include "OptimizedCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_OPTIMIZED_CPP_STATIC

DLL_MAIN_FUNCTION(OptimizedCpp);

#else  // BUILDING_OPTIMIZED_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(OptimizedCpp);

#endif  // !BUILDING_OPTIMIZED_CPP_STATIC
