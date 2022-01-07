///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:21)

#include "Example/BookOperatingSystem/ComputerSystemsAProgrammersPerspective/ComputerSystemsAProgrammersPerspectiveExport.h"

#include "ComputerSystemsAProgrammersPerspectiveFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC

DLL_MAIN_FUNCTION(ComputerSystemsAProgrammersPerspective);

#else  // !BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC

CORE_TOOLS_MUTEX_INIT(ComputerSystemsAProgrammersPerspective);

#endif  // BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC
