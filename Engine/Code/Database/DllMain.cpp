//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:28)

#include "Database/DatabaseExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Database/DatabaseFwd.h"

#ifndef BUILDING_DATABASE_STATIC

DLL_MAIN_FUNCTION(Database);

#else  // !BUILDING_DATABASE_STATIC

CORE_TOOLS_MUTEX_INIT(Database);

#endif  // !BUILDING_DATABASE_STATIC