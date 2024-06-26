///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 15:53)

#include "Interface/InterfaceExport.h"

#include "InterfaceFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INTERFACE_STATIC

DLL_MAIN_FUNCTION(Interface);

#else  // !BUILDING_INTERFACE_STATIC

CORE_TOOLS_MUTEX_INIT(Interface);

#endif  // BUILDING_INTERFACE_STATIC
