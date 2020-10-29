//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 13:36)

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

        [[nodiscard]] ResultPtr ExecuteDoc(const std::string& findStatement, const BindStatementType& bindStatement, int limitStatement) override;

    private:
        using MysqlxCollectionPtr = std::unique_ptr<MysqlxCollection>;

    private:
        [[nodiscard]] static MysqlxCollectionPtr GetMysqlxCollectionPtr(const Schema& schema, const std::string& collectionName);

    private:
        MysqlxCollectionPtr m_MysqlxCollection;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_COLLECTION_H
