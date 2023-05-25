///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.9 (2023/05/25 11:26)

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetExport.h"

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_STATIC

DLL_MAIN_FUNCTION(Database);

#else  // !BUILDING_DATABASE_STATIC

CORE_TOOLS_MUTEX_INIT(Database);

#endif  // !BUILDING_DATABASE_STATIC
