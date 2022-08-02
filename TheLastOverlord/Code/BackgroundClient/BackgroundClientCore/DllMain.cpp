///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 22:44)

#include "BackgroundClientCoreExport.h"

#include "BackgroundClientCoreFwd.h"
#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

DLL_MAIN_FUNCTION(BackgroundClientCore);

#else  // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

CORE_TOOLS_MUTEX_INIT(BackgroundClientCore);

#endif  // BUILDING_BACKGROUND_CLIENT_CORE_STATIC
