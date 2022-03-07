///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 16:04)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_H

#include "Database/DatabaseDll.h"

#include "ResultRow.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

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
        using MysqlxDocResultSharedPtr = std::shared_ptr<MysqlxDocResult>;
        using MysqlxRowResultSharedPtr = std::shared_ptr<MysqlxRowResult>;

    public:
        explicit Result(const ConfigurationStrategy& configurationStrategy);
        Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultSharedPtr& mysqlxDocResult);
        Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultSharedPtr& mysqlxRowResult);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual ResultRowPtr FetchOne();
        NODISCARD virtual ResultRowContainer FetchAll();

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_H
