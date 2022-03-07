///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:43)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/ResultRowImpl.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorDocResultRow : public ResultRowImpl
    {
    public:
        using ClassType = MysqlConnectorDocResultRow;
        using ParentType = ResultRowImpl;
        using MysqlxDbDocSharedPtr = std::shared_ptr<MysqlxDbDoc>;

    public:
        MysqlConnectorDocResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocSharedPtr& mysqlxDbDoc) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Print(std::ostream& os) const override;

        NODISCARD int GetColCount() const noexcept override;

    private:
        MysqlxDbDocSharedPtr mysqlxDbDoc;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DOC_RESULT_ROW_H
