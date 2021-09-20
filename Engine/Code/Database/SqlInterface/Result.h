//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:01)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultRow.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <vector>

DATABASE_NON_COPY_EXPORT_IMPL(ResultImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Result final
    {
    public:
        NON_COPY_TYPE_DECLARE(Result);
        using ResultRowPtr = std::unique_ptr<ResultRow>;
        using ResultRowContainer = std::vector<ResultRowPtr>;

    public:
        explicit Result(const ConfigurationStrategy& configurationStrategy);
        virtual ~Result() noexcept = default;
        Result(const Result& rhs) = delete;
        Result& operator=(const Result& rhs) = delete;
        Result(Result&& rhs) noexcept = default;
        Result& operator=(Result&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] virtual ResultRowPtr FetchOne();
        [[nodiscard]] virtual ResultRowContainer FetchAll();

    private:
        PackageType impl;

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    public:
        using MysqlxDocResultPtr = std::shared_ptr<MysqlxDocResult>;
        using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

    public:
        Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult);
        Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult);
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_H
