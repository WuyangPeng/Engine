///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/06 21:46)

#include "Example/BookOperatingSystem/SystematicReuseWithACEAndFrameworks/SystematicReuseWithACEAndFrameworksExport.h"

#include "SystematicReuseWithACEAndFrameworks.h"

#ifndef BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC

    #include "DllLib.h"

#else  // !BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC

namespace SystematicReuseWithACEAndFrameworks
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_SYSTEMATIC_REUSE_WITH_ACE_AND_FRAMEWORKS_STATIC
