///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:49)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Database/DatabaseExample/DatabaseExampleFwd.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(DatabaseExample);

#else  // !BUILDING_DATABASE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseExample);

#endif  // !BUILDING_DATABASE_EXAMPLE_STATIC
