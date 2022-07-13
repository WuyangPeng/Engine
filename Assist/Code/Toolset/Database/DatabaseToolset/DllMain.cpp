///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:24)

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetExport.h"

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_STATIC

DLL_MAIN_FUNCTION(Database);

#else  // !BUILDING_DATABASE_STATIC

CORE_TOOLS_MUTEX_INIT(Database);

#endif  // !BUILDING_DATABASE_STATIC
