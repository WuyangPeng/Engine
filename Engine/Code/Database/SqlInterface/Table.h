///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:21)

#ifndef DATABASE_SQL_INTERFACE_TABLE_H
#define DATABASE_SQL_INTERFACE_TABLE_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#include <map>
#include <string>

DATABASE_NON_COPY_EXPORT_IMPL(TableImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Table final
    {
    public:
        NON_COPY_TYPE_DECLARE(Table);
        using ResultSharedPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;
        using StatementType = std::initializer_list<std::string>;

    public:
        Table(const Schema& schema, const std::string& tableName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD ResultSharedPtr Select(StatementType selectStatement,
                                         const std::string& whereStatement,
                                         const std::string& orderByStatement,
                                         const BindStatementType& bindStatement);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_H
