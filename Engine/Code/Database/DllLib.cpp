///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 15:06)

#include "Database/DatabaseExport.h"

#include "Database/Database.h"

#ifndef BUILDING_DATABASE_STATIC

    #include "DllLib.h"

#else  // BUILDING_DATABASE_STATIC

namespace Database
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_DATABASE_STATIC
