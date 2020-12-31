//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:38)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/ResultRowImpl.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorResultRow : public ResultRowImpl
    {
    public:
        using ClassType = MysqlConnectorResultRow;
        using ParentType = ResultRowImpl;
        using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

    public:
        explicit MysqlConnectorResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Print(std::ostream& os) const override;

        [[nodiscard]] int GetIntValue(int pos) const override;
        [[nodiscard]] uint32_t GetUIntValue(int pos) const override;
        [[nodiscard]] int64_t GetInt64Value(int pos) const override;
        [[nodiscard]] uint64_t GetUInt64Value(int pos) const override;
        [[nodiscard]] float GetFloatValue(int pos) const override;
        [[nodiscard]] double GetDoubleValue(int pos) const override;
        [[nodiscard]] bool GetBoolValue(int pos) const override;
        [[nodiscard]] std::string GetStringValue(int pos) const override;
        [[nodiscard]] std::wstring GetWStringValue(int pos) const override;

        int GetColCount() const override;

    private:
        MysqlxRowPtr m_MysqlxRow;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
