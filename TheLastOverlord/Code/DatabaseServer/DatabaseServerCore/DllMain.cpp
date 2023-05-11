///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 20:46)

#include "DatabaseServerCoreExport.h"

#include "DatabaseServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(DatabaseServerCore);

#else  // !BUILDING_DATABASE_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseServerCore);

#endif  // BUILDING_DATABASE_SERVER_CORE_STATIC