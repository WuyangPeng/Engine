///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.2 (2022/09/18 14:44)

#ifndef BUILDING_STATIC

    #include "DllLib.h"

#else  // BUILDING_STATIC

namespace ExportTest
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_STATIC