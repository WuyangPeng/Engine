//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:57)

#ifndef DATABASE_SQL_INTERFACE_TABLE_FACTORY_H
#define DATABASE_SQL_INTERFACE_TABLE_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#include <string>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE TableFactory final
    {
    public:
        using ClassType = TableFactory;
        using ImplType = TableImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        TableFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const Schema& schema, const std::string& tableName);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_FACTORY_H
