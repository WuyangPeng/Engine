///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 11:04)

#include "Example/Database/DatabaseExample/DatabaseExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Database/DatabaseExample/DatabaseExampleFwd.h"

#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(DatabaseExample);

#else  // !BUILDING_DATABASE_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseExample);

#endif  // !BUILDING_DATABASE_EXAMPLE_STATIC
