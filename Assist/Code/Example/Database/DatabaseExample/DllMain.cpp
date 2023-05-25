///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.9 (2023/05/25 11:28)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Database/DatabaseExample/DatabaseExampleFwd.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(DatabaseExample);

#else  // !BUILDING_DATABASE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseExample);

#endif  // !BUILDING_DATABASE_EXAMPLE_STATIC
