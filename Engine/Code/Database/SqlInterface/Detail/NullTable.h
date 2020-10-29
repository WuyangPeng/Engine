//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:49)

#ifndef DATABASE_SQL_INTERFACE_NULL_TABLE_H
#define DATABASE_SQL_INTERFACE_NULL_TABLE_H

#include "Database/DatabaseDll.h"

#include "TableImpl.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullTable final : public TableImpl
    {
    public:
        using ClassType = NullTable;
        using ParentType = TableImpl;

    public:
        explicit NullTable(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // DATABASE_SQL_INTERFACE_NULL_TABLE_H
