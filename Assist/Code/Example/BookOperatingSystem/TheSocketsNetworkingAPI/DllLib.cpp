///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/08 21:14)

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
