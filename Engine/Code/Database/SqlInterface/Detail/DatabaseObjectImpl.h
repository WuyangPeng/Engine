//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:47)

#ifndef DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
#define DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseObjectImpl
    {
    public:
        using ClassType = DatabaseObjectImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using MysqlxSessionPtr = std::unique_ptr<MysqlxSession>;

    public:
        explicit DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~DatabaseObjectImpl() noexcept = 0;
        DatabaseObjectImpl(const DatabaseObjectImpl& rhs) = default;
        DatabaseObjectImpl& operator=(const DatabaseObjectImpl& rhs) = default;
        DatabaseObjectImpl(DatabaseObjectImpl&& rhs) noexcept = default;
        DatabaseObjectImpl& operator=(DatabaseObjectImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        [[nodiscard]] virtual MysqlxSessionPtr GetMysqlxSessionPtr();

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DATABASE_OBJECT_IMPL_H
