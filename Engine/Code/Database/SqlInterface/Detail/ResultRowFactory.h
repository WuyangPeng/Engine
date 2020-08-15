// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/16 11:26)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultRowFactory
    {
    public:
        using ClassType = ResultRowFactory;
        using ImplType = ResultRowImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;
        using MysqlxDbDocPtr = std::shared_ptr<MysqlxDbDoc>;
        using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

    public:
        ResultRowFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc);
        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow);
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
