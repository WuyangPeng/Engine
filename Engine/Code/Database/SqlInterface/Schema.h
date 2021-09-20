//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_H
#define DATABASE_SQL_INTERFACE_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
DATABASE_NON_COPY_EXPORT_IMPL(SchemaImpl); 

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Schema final  
    {
    public:
        NON_COPY_TYPE_DECLARE(Schema);

    public:
        explicit Schema(const Session& session);
        Schema(const Session& session, int dbIndex);
        ~Schema() noexcept = default;
        Schema(const Schema& rhs) noexcept = delete;
        Schema& operator=(const Schema& rhs) noexcept = delete;
        Schema(Schema&& rhs) noexcept = delete;
        Schema& operator=(Schema&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

    private:
        PackageType impl;

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
