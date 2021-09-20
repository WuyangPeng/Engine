///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.1 (2021/01/01 14:26)

#include "Example/BookCpp/ComputingConceptsWithCppEssentials/ComputingConceptsWithCppEssentialsExport.h"

#include "ComputingConceptsWithCppEssentialsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC

DLL_MAIN_FUNCTION(ComputingConceptsWithCppEssentials);

#else  // BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC

CORE_TOOLS_MUTEX_INIT(ComputingConceptsWithCppEssentials);

#endif  // !BUILDING_COMPUTING_CONCEPTS_WITH_CPP_ESSENTIALS_STATIC
