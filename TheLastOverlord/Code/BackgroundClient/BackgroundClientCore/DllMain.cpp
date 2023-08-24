/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��0.9.1.3 (2023/08/21 10:42)

#include "BackgroundClientCoreExport.h"

#include "BackgroundClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(BackgroundClientCore);

#else  // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(BackgroundClientCore);

#endif  // BUILDING_BACKGROUND_CLIENT_CORE_STATIC