///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:12)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/CollectionImpl.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorCollection : public CollectionImpl
    {
    public:
        using ClassType = MysqlConnectorCollection;
        using ParentType = CollectionImpl;

    public:
        explicit MysqlConnectorCollection(const Schema& schema, const std::string& collectionName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ResultSharedPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement) override;

    private:
        using MysqlxCollectionUniquePtr = std::unique_ptr<MysqlxCollection>;

    private:
        MysqlxCollectionUniquePtr mysqlxCollection;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H
