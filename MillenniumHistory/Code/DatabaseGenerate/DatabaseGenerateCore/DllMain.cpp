/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "DatabaseGenerateCoreExport.h"

#include "DatabaseGenerateCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_GENERATE_CORE_STATIC

DLL_MAIN_FUNCTION(DatabaseGenerateCore);

#else  // !BUILDING_DATABASE_GENERATE_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(DatabaseGenerateCore);

#endif  // BUILDING_DATABASE_GENERATE_CORE_STATIC