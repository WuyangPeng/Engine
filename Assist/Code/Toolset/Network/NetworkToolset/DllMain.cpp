///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.8 (2023/05/10 18:16)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Network/NetworkToolset/NetworkToolsetFwd.h"

#ifndef BUILDING_NETWORK_STATIC

DLL_MAIN_FUNCTION(Network);

#else  // !BUILDING_NETWORK_STATIC

CORE_TOOLS_MUTEX_INIT(Network);

#endif  // !BUILDING_NETWORK_STATIC
