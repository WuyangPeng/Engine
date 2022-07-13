///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 20:55)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleFwd.h"

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(UserInterfaceExample);

#else  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterfaceExample);

#endif  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
