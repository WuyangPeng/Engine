///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:14)

#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/UserInterface/UserInterfaceToolset/UserInterfaceToolsetFwd.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

DLL_MAIN_FUNCTION(UserInterface);

#else  // !BUILDING_USER_INTERFACE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterface);

#endif  // !BUILDING_USER_INTERFACE_STATIC
