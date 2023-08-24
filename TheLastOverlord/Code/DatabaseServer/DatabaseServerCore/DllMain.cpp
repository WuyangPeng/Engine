/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#include "DatabaseServerCoreExport.h"

#include "DatabaseServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(DatabaseServerCore);

#else  // !BUILDING_DATABASE_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseServerCore);

#endif  // BUILDING_DATABASE_SERVER_CORE_STATIC