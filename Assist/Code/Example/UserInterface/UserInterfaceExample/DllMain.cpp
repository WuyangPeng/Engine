///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:45)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleFwd.h"

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(UserInterfaceExample);

#else  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterfaceExample);

#endif  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
