///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 19:49)

#include "UserInterface/UserInterfaceExport.h"

#include "UserInterface/UserInterfaceFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_USER_INTERFACE_STATIC

DLL_MAIN_FUNCTION(UserInterface);

#else  // !BUILDING_USER_INTERFACE_STATIC

CORE_TOOLS_MUTEX_INIT(UserInterface);

#endif  // !BUILDING_USER_INTERFACE_STATIC