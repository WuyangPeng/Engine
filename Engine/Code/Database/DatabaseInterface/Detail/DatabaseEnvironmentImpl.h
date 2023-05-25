///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 20:42)

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