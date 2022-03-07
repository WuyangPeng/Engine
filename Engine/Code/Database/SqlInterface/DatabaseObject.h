///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:45)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

DATABASE_NON_COPY_EXPORT_IMPL(DatabaseObjectImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseObject final
    {
    public:
        NON_COPY_TYPE_DECLARE(DatabaseObject);
        using MysqlxSessionUniquePtr = std::unique_ptr<MysqlxSession>;

    public:
        explicit DatabaseObject(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD MysqlxSessionUniquePtr GetMysqlxSession() const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_H
