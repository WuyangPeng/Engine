///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 8:44)

#include "Example/BookOperatingSystem/PrinciplesProtocolsAndArchitectures/PrinciplesProtocolsAndArchitecturesExport.h"

#include "PrinciplesProtocolsAndArchitecturesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

DLL_MAIN_FUNCTION(PrinciplesProtocolsAndArchitectures);

#else  // !BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

CORE_TOOLS_MUTEX_INIT(PrinciplesProtocolsAndArchitectures);

#endif  // BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC
