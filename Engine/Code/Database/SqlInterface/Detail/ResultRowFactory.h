//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:50)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultRowFactory final
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

        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc);
        [[nodiscard]] static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow);
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_FACTORY_H
