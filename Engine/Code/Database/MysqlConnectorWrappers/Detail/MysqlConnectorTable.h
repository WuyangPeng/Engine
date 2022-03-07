///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:47)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_TABLE_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_TABLE_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/TableImpl.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#include <initializer_list>
#include <string>

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorTable : public TableImpl
    {
    public:
        using ClassType = MysqlConnectorTable;
        using ParentType = TableImpl;

    public:
        MysqlConnectorTable(const Schema& schema, const std::string& tableName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ResultSharedPtr Select(StatementType selectStatement,
                                         const std::string& whereStatement,
                                         const std::string& orderByStatement,
                                         const BindStatementType& bindStatement) override;

    private:
        using MysqlxTableUniquePtr = std::unique_ptr<MysqlxTable>;

    private:
        MysqlxTableUniquePtr mysqlxTable;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_TABLE_H
