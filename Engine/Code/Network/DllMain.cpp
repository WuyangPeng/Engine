///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/27 14:35)

#include "Network/NetworkExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Network/NetworkFwd.h"

#ifndef BUILDING_NETWORK_STATIC

DLL_MAIN_FUNCTION(Network);

#else  // !BUILDING_NETWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Network);

#endif  // !BUILDING_NETWORK_STATIC