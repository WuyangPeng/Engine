///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:46)

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

        NODISCARD int GetIntValue(int pos) const override;
        NODISCARD uint32_t GetUIntValue(int pos) const override;
        NODISCARD int64_t GetInt64Value(int pos) const override;
        NODISCARD uint64_t GetUInt64Value(int pos) const override;
        NODISCARD float GetFloatValue(int pos) const override;
        NODISCARD double GetDoubleValue(int pos) const override;
        NODISCARD bool GetBoolValue(int pos) const override;
        NODISCARD std::string GetStringValue(int pos) const override;
        NODISCARD std::wstring GetWStringValue(int pos) const override;

        NODISCARD int GetColCount() const override;

    private:
        MysqlxRowPtr mysqlxRow;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_RESULT_ROW_H
