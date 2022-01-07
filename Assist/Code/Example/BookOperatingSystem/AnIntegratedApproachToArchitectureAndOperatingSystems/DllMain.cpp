///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/06 21:21)

#include "Example/BookOperatingSystem/AnIntegratedApproachToArchitectureAndOperatingSystems/ComputerSystemsAnIntegratedApproachToArchitectureAndOperatingSystemsExport.h"

#include "ComputerSystemsAnIntegratedApproachToArchitectureAndOperatingSystemsFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_STATIC

DLL_MAIN_FUNCTION(ComputerSystemsAnIntegratedApproachToArchitectureAndOperatingSystems);

#else  // !BUILDING_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_STATIC

CORE_TOOLS_MUTEX_INIT(ComputerSystemsAnIntegratedApproachToArchitectureAndOperatingSystems);

#endif  // BUILDING_COMPUTER_SYSTEMS_AN_INTEGRATED_APPROACH_TO_ARCHITECTURE_AND_OPERATING_SYSTEMS_STATIC
