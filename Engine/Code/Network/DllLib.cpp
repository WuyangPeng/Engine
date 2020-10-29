//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 17:06)

// 网络库（Network）封装了引擎的网络层调用。
// 网络库位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并使用boost、stlsoft和ACE工具库。

#include "Network/NetworkExport.h"

#ifndef BUILDING_NETWORK_STATIC

    #include "DllLib.h"

#else  // BUILDING_NETWORK_STATIC

namespace Network
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_NETWORK_STATIC