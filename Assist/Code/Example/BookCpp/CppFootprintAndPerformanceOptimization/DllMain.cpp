///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/16 2:01)

#include "Example/BookCpp/CppFootprintAndPerformanceOptimization/CppFootprintAndPerformanceOptimizationExport.h"

#include "CppFootprintAndPerformanceOptimizationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

DLL_MAIN_FUNCTION(CppFootprintAndPerformanceOptimization);

#else  // BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

CORE_TOOLS_MUTEX_INIT(CppFootprintAndPerformanceOptimization);

#endif  // !BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC
