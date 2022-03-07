///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/15 13:25)

#include "Network/NetworkExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Network/NetworkFwd.h"

#ifndef BUILDING_NETWORK_STATIC

DLL_MAIN_FUNCTION(Network);

#else  // !BUILDING_NETWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Network);

#endif  // !BUILDING_NETWORK_STATIC