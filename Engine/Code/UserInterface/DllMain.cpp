/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 14:44)

#include "UserInterface/UserInterfaceExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "UserInterface/UserInterfaceFwd.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

DLL_MAIN_FUNCTION(UserInterface);

#else  // !BUILDING_USER_INTERFACE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterface);

#endif  // !BUILDING_USER_INTERFACE_STATIC