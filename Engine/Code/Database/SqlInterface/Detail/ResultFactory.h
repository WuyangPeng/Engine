//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 9:49)

#ifndef DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H
#define DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultFactory final
    {
    public:
        using ClassType = ResultFactory;
        using ImplType = ResultImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;
        using MysqlxDocResultPtr = std::shared_ptr<MysqlxDocResult>;
        using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

    public:
        ResultFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult);
        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H
