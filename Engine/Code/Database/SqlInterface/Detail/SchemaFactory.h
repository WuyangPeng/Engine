// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 11:26)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H
#define DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SchemaFactory
    {
    public:
        using ClassType = SchemaFactory;
        using ImplType = SchemaImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        SchemaFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        static ImplTypePtr Create(const Session& session);
        static ImplTypePtr Create(const Session& session, int dbIndex);
        static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H
