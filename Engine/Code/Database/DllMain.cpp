///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.9 (2023/05/22 15:06)

#include "Database/DatabaseExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Database/DatabaseFwd.h"

#ifndef BUILDING_DATABASE_STATIC

DLL_MAIN_FUNCTION(Database);

#else  // !BUILDING_DATABASE_STATIC

CORE_TOOLS_MUTEX_INIT(Database);

#endif  // !BUILDING_DATABASE_STATIC