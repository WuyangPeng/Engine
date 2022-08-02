///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/22 22:44)

#include "BackgroundClientCoreExport.h"

#include "BackgroundClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(BackgroundClientCore);

#else  // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(BackgroundClientCore);

#endif  // BUILDING_BACKGROUND_CLIENT_CORE_STATIC
