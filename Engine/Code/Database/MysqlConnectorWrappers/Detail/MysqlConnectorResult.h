//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:38)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/ResultImpl.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorResult : public ResultImpl
    {
    public:
        using ClassType = MysqlConnectorResult;
        using ParentType = ResultImpl;
        using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

    public:
        MysqlConnectorResult(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] ResultRowPtr FetchOne() override;
        [[nodiscard]] ResultRowContainer FetchAll() override;

    private:
        MysqlxRowResultPtr m_MysqlxRowResult;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_H
