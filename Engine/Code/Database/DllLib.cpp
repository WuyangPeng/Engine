//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 19:27)

// 数据库（Database）位于引擎的第三层，只允许调用引擎中的System、CoreTools库，并使用boost、stlsoft和其他数据库相关的工具库。
// 主要对MySQL、SQL Server和一个平面文件数据库进行封装。

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
