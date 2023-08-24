///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:20)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"

DATABASE_EXPORT_UNIQUE_PTR(DatabaseEnvironment);
DATABASE_NON_COPY_EXPORT_IMPL(DatabaseEnvironmentImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseEnvironment final : public CoreTools::Singleton<DatabaseEnvironment>
    {
    public:
        NON_COPY_TYPE_DECLARE(DatabaseEnvironment);
        using ParentType = Singleton<DatabaseEnvironment>;

    private:
        enum class DatabaseEnvironmentCreate
        {
            Init,
        };

    public:
        explicit DatabaseEnvironment(DatabaseEnvironmentCreate databaseEnvironmentCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(Log)

        CLASS_INVARIANT_DECLARE;

        void InitEnvironment(const ConfigurationStrategy& configurationStrategy);

    private:
        using DatabaseEnvironmentUniquePtr = std::unique_ptr<DatabaseEnvironment>;

    private:
        static DatabaseEnvironmentUniquePtr databaseEnvironment;
        PackageType impl;
    };
}

#define DATABASE_ENVIRONMENT_SINGLETON Database::DatabaseEnvironment::GetSingleton()

#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENVIRONMENT_H