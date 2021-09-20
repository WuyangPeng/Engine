//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_SESSION_H
#define DATABASE_SQL_INTERFACE_SESSION_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Result.h"
#include "Schema.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

DATABASE_NON_COPY_EXPORT_IMPL(SessionImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Session final 
    {
    public:
        NON_COPY_TYPE_DECLARE(Session);
        using SchemaPtr = std::unique_ptr<Schema>;
        using SchemaContainer = std::vector<SchemaPtr>;
        using ResultPtr = std::shared_ptr<Result>;

    public:
        explicit Session(const ConfigurationStrategy& configurationStrategy);
        explicit Session(const DatabaseObject& databaseObject);
        ~Session() noexcept = default;
        Session(const Session& rhs) noexcept = delete;
        Session& operator=(const Session& rhs) noexcept = delete;
        Session(Session&& rhs) noexcept = delete;
        Session& operator=(Session&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] SchemaContainer GetSchemaContainer();

        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement);
        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement);
        void Execute(const std::string& findStatement, int bindStatement);
        void Execute(const std::string& findStatement, const std::string& bindStatement);
        void Execute(const std::string& findStatement);

    private:
        PackageType impl;

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    public:
        using SessionWeakPtr = std::weak_ptr<ImplType>;

    public:
        [[nodiscard]] SessionWeakPtr GetImplType() const noexcept;
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_H
