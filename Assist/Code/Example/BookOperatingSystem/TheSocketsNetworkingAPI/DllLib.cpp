///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#include "Example/BookOperatingSystem/TheSocketsNetworkingAPI/TheSocketsNetworkingAPIExport.h"

#include "TheSocketsNetworkingAPI.h"

#ifndef BUILDING_THE_SOCKETS_NETWORKING_API_STATIC

    #include "DllLib.h"

#else  // !BUILDING_THE_SOCKETS_NETWORKING_API_STATIC

namespace TheSocketsNetworkingAPI
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_THE_SOCKETS_NETWORKING_API_STATIC
