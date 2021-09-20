///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:50)

#include "Example/BookCpp/TheDesignAndEvolutionOfCpp/TheDesignAndEvolutionOfCppExport.h"

#include "TheDesignAndEvolutionOfCppFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC

DLL_MAIN_FUNCTION(TheDesignAndEvolutionOfCpp);

#else  // BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC

CORE_TOOLS_MUTEX_INIT(TheDesignAndEvolutionOfCpp);

#endif  // !BUILDING_THE_DESIGN_AND_EVOLUTION_OF_CPP_STATIC
