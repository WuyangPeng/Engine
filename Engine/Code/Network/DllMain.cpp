///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 10:50)

#include "Network/NetworkExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Network/NetworkFwd.h"

#ifndef BUILDING_NETWORK_STATIC

DLL_MAIN_FUNCTION(Network);

#else  // !BUILDING_NETWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Network);

#endif  // !BUILDING_NETWORK_STATIC