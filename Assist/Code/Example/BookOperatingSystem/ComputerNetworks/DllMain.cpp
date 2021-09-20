///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:20)

#include "Example/BookOperatingSystem/ComputerNetworks/ComputerNetworksExport.h"

#include "ComputerNetworksFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_COMPUTER_NETWORKS_STATIC

DLL_MAIN_FUNCTION(ComputerNetworks);

#else  // !BUILDING_COMPUTER_NETWORKS_STATIC

CORE_TOOLS_MUTEX_INIT(ComputerNetworks);

#endif  // BUILDING_COMPUTER_NETWORKS_STATIC
