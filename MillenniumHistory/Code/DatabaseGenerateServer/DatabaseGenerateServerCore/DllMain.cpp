///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	ǧ��ʷ�߰汾��0.9.0.12 (2023/06/12 21:50)

#include "DatabaseGenerateServerCoreExport.h"

#include "DatabaseGenerateServerCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC

DLL_MAIN_FUNCTION(DatabaseGenerateServerCore);

#else  // !BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseGenerateServerCore);

#endif  // BUILDING_DATABASE_GENERATE_SERVER_CORE_STATIC