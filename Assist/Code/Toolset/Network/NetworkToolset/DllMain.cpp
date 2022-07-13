///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 11:53)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Network/NetworkToolset/NetworkToolsetFwd.h"

#ifndef BUILDING_NETWORK_STATIC

DLL_MAIN_FUNCTION(Network);

#else  // !BUILDING_NETWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Network);

#endif  // !BUILDING_NETWORK_STATIC
