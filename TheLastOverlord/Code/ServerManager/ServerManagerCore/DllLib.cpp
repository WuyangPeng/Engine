///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 23:07)

#include "ServerManagerCoreExport.h"

#include "DllLib.h"
#include "ServerManagerCore.h"

#ifdef BUILDING_SERVER_MANAGER_CORE_STATIC

namespace ServerManagerCore
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SERVER_MANAGER_CORE_STATIC
