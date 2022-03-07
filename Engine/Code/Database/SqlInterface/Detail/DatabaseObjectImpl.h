///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 13:51)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseObjectImpl
    {
    public:
        using ClassType = DatabaseObjectImpl;
        using FactoryType = DatabaseObjectFactory;
        using MysqlxSessionUniquePtr = std::unique_ptr<MysqlxSession>;

    public:
        explicit DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~DatabaseObjectImpl() noexcept = 0;
        DatabaseObjectImpl(const DatabaseObjectImpl& rhs) noexcept = default;
        DatabaseObjectImpl& operator=(const DatabaseObjectImpl& rhs) noexcept = default;
        DatabaseObjectImpl(DatabaseObjectImpl&& rhs) noexcept = default;
        DatabaseObjectImpl& operator=(DatabaseObjectImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD virtual MysqlxSessionUniquePtr GetMysqlxSession() const;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
