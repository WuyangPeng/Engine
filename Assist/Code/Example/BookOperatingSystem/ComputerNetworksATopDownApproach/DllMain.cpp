///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/ComputerNetworksATopDownApproach/ComputerNetworksATopDownApproachExport.h"

#include "ComputerNetworksATopDownApproachFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC

DLL_MAIN_FUNCTION(ComputerNetworksATopDownApproach);

#else  // !BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC

CORE_TOOLS_MUTEX_INIT(ComputerNetworksATopDownApproach);

#endif  // BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC
