///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.2 (2021/08/27 22:20)

#include "Example/BookOperatingSystem/ComputerNetworks/ComputerNetworksExport.h"

#include "ComputerNetworks.h"

#ifndef BUILDING_COMPUTER_NETWORKS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_COMPUTER_NETWORKS_STATIC

namespace ComputerNetworks
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_COMPUTER_NETWORKS_STATIC
