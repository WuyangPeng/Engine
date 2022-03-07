///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:43)

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

        NODISCARD ResultRowUniquePtr FetchOne() override;
        NODISCARD ResultRowContainer FetchAll() override;

    private:
        MysqlxRowResultPtr mysqlxRowResult;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_H
