/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:46)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_IMPL_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MongoWrappers/Detail/MongoEnvironment.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseEnvironmentImpl
    {
    public:
        using ClassType = DatabaseEnvironmentImpl;

    public:
        DatabaseEnvironmentImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void InitEnvironment(const ConfigurationStrategy& configurationStrategy);

    private:
        MongoEnvironment mongoEnvironment;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_IMPL_H