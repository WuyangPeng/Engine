///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/06 21:46)

#include "Example/BookOperatingSystem/SystematicReuseWithACEAndFrameworks/SystematicReuseWithACEAndFrameworksExport.h"

#include "SystematicReuseWithACEAndFrameworksFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC

DLL_MAIN_FUNCTION(SystematicReuseWithACEAndFrameworks);

#else  // !BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC

CORE_TOOLS_MUTEX_INIT(SystematicReuseWithACEAndFrameworks);

#endif  // BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC
