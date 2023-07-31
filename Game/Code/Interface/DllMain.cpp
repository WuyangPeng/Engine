///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 15:53)

#include "Interface/InterfaceExport.h"

#include "InterfaceFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTERFACE_STATIC

DLL_MAIN_FUNCTION(Interface);

#else  // !BUILDING_INTERFACE_STATIC

CORE_TOOLS_MUTEX_INIT(Interface);

#endif  // BUILDING_INTERFACE_STATIC
