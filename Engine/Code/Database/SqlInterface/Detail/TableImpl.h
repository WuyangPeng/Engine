///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:42)

#ifndef DATABASE_SQL_INTERFACE_TABLE_IMPL_H
#define DATABASE_SQL_INTERFACE_TABLE_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#include <map>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE TableImpl
    {
    public:
        using ClassType = TableImpl;
        using FactoryType = TableFactory;
        using ResultSharedPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;
        using StatementType = std::initializer_list<std::string>;

    public:
        explicit TableImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~TableImpl() noexcept = default;
        TableImpl(const TableImpl& rhs) noexcept = default;
        TableImpl& operator=(const TableImpl& rhs) noexcept = default;
        TableImpl(TableImpl&& rhs) noexcept = default;
        TableImpl& operator=(TableImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual ResultSharedPtr Select(StatementType selectStatement,
                                                 const std::string& whereStatement,
                                                 const std::string& orderByStatement,
                                                 const BindStatementType& bindStatement);

    public:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_IMPL_H
