///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.3 (2021/05/19 23:07)

#include "Example/BookOperatingSystem/TheOldNewThing/TheOldNewThingExport.h"

#include "TheOldNewThingFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_THE_OLD_NEW_THING_STATIC

DLL_MAIN_FUNCTION(TheOldNewThing);

#else  // !BUILDING_THE_OLD_NEW_THING_STATIC

CORE_TOOLS_MUTEX_INIT(TheOldNewThing);

#endif  // BUILDING_THE_OLD_NEW_THING_STATIC
