﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 14:22)

#ifndef DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_DATABASE_FLUSH_H
#define DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_DATABASE_FLUSH_H

#include "Database/DatabaseDll.h"

#include "MysqlConnectorConnection.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"
#include "Database/DatabaseInterface/Detail/DatabaseFlushImpl.h"

#include <vector>

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorDatabaseFlush final : public DatabaseFlushImpl
    {
    public:
        using ClassType = MysqlConnectorDatabaseFlush;
        using ParentType = DatabaseFlushImpl;
        using MysqlConnectorConnectionSharedPtr = std::shared_ptr<MysqlConnectorConnection>;
        using Container = std::vector<MysqlConnectorConnectionSharedPtr>;

    public:
        explicit MysqlConnectorDatabaseFlush(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void ChangeDatabase(int64_t userId, const BasisDatabaseContainer& basisDatabaseContainer) override;

        NODISCARD BasisDatabaseContainer SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const override;
        NODISCARD ResultContainer SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const override;

    private:
        void CheckWrappersStrategy(const BasisDatabaseContainer& basisDatabaseContainer) const;

    private:
        Container connection;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_MYSQL_CONNECTOR_WRAPPERS_MYSQL_CONNECTOR_DATABASE_FLUSH_H