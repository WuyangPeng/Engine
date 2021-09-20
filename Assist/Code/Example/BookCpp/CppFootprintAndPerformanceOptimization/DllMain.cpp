///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/16 2:01)

#include "Example/BookCpp/CppFootprintAndPerformanceOptimization/CppFootprintAndPerformanceOptimizationExport.h"

#include "CppFootprintAndPerformanceOptimizationFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

DLL_MAIN_FUNCTION(CppFootprintAndPerformanceOptimization);

#else  // BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC

CORE_TOOLS_MUTEX_INIT(CppFootprintAndPerformanceOptimization);

#endif  // !BUILDING_CPP_FOOTPRINT_AND_PERFORMANCE_OPTIMIZATION_STATIC
