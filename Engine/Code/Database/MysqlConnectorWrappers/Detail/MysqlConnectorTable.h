// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:48)

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

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        ResultPtr Select(std::initializer_list<std::string> selectStatement, const std::string& whereStatement,
                         const std::string& orderByStatement, const BindStatementType& bindStatement) override;

    private:
        using MysqlxTablePtr = std::unique_ptr<MysqlxTable>;

    private:
        static MysqlxTablePtr GetMysqlxTablePtr(const Schema& schema, const std::string& tableName);

    private:
        MysqlxTablePtr m_MysqlxTable;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_TABLE_H
