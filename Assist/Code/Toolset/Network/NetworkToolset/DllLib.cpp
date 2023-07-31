///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:38)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "Toolset/Network/NetworkToolset/NetworkToolset.h"

#ifndef BUILDING_NETWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_STATIC

namespace NetworkToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_STATIC