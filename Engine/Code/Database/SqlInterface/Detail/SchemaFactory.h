///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:06)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H
#define DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SchemaFactory final
    {
    public:
        using ClassType = SchemaFactory;
        using ImplType = SchemaImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        SchemaFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const Session& session);
        NODISCARD static ImplTypeSharedPtr Create(const Session& session, int dbIndex);
        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_FACTORY_H
