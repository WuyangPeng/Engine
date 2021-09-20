///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#include "Example/BookCpp/UnderstandingTheMachine/UnderstandingTheMachineExport.h"

#include "UnderstandingTheMachineFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_UNDERSTANDING_THE_MACHINE_STATIC

DLL_MAIN_FUNCTION(UnderstandingTheMachine);

#else  // BUILDING_UNDERSTANDING_THE_MACHINE_STATIC

CORE_TOOLS_MUTEX_INIT(UnderstandingTheMachine);

#endif  // !BUILDING_UNDERSTANDING_THE_MACHINE_STATIC
