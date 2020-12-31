//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_H
#define DATABASE_SQL_INTERFACE_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

DATABASE_EXPORT_SHARED_PTR(SchemaImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Schema final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Schema);

    public:
        explicit Schema(const Session& session);
        Schema(const Session& session, int dbIndex);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        IMPL_TYPE_DECLARE(Schema);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    public:
        using SchemaWeakPtr = std::weak_ptr<ImplType>;

    public:
        [[nodiscard]] SchemaWeakPtr GetImplType() const noexcept;
        Schema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_H
