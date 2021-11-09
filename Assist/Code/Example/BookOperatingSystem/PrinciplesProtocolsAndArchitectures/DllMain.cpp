///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 8:44)

#include "Example/BookOperatingSystem/PrinciplesProtocolsAndArchitectures/PrinciplesProtocolsAndArchitecturesExport.h"

#include "PrinciplesProtocolsAndArchitecturesFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

DLL_MAIN_FUNCTION(PrinciplesProtocolsAndArchitectures);

#else  // !BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC

CORE_TOOLS_MUTEX_INIT(PrinciplesProtocolsAndArchitectures);

#endif  // BUILDING_PRINCIPLES_PROTOCOLS_AND_ARCHITECTURES_STATIC
