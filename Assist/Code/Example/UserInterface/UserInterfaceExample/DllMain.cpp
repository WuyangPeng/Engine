///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 20:55)

#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/UserInterface/UserInterfaceExample/UserInterfaceExampleFwd.h"

#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(UserInterfaceExample);

#else  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterfaceExample);

#endif  // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC
