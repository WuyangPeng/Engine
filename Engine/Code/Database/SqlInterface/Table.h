//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_TABLE_H
#define DATABASE_SQL_INTERFACE_TABLE_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <map>
#include <string>

DATABASE_NON_COPY_EXPORT_IMPL(TableImpl); 

namespace Database
{
    class TableFactory;
    class DATABASE_DEFAULT_DECLARE Table final  
    {
    public:
        NON_COPY_TYPE_DECLARE(Table);
        using ResultPtr = std::shared_ptr<Result>;
        using BindStatementType = std::map<std::string, std::string>;
        
    public:
        Table(const Schema& schema, const std::string& tableName);
        ~Table() noexcept = default;
        Table(const Table& rhs) noexcept = delete;
        Table& operator=(const Table& rhs) noexcept = delete;
        Table(Table&& rhs) noexcept = delete;
        Table& operator=(Table&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] ResultPtr Select(std::initializer_list<std::string> selectStatement, const std::string& whereStatement,
                                       const std::string& orderByStatement, const BindStatementType& bindStatement);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_H
