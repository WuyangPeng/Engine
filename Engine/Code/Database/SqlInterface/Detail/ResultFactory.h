// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:25)

#ifndef DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H
#define DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE ResultFactory
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

        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult);
        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult);
    };
}

#endif  // DATABASE_SQL_INTERFACE_TABLE_DOC_FACTORY_H
