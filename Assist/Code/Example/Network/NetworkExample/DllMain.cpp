///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.8 (2023/05/10 18:19)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/Network/NetworkExample/NetworkExampleFwd.h"

#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(NetworkExample);

#else  // !BUILDING_NETWORK_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(NetworkExample);

#endif  // !BUILDING_NETWORK_EXAMPLE_STATIC
