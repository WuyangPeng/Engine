///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:44)

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetExport.h"

#include "Toolset/Database/DatabaseToolset/DatabaseToolset.h"

#ifndef BUILDING_DATABASE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_STATIC

namespace DatabaseToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_STATIC
