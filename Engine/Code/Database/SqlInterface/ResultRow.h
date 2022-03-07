///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:09)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

#include <string>

DATABASE_NON_COPY_EXPORT_IMPL(ResultRowImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ResultRow final
    {
    public:
        NON_COPY_TYPE_DECLARE(ResultRow);
        using MysqlxDbDocSharedPtr = std::shared_ptr<MysqlxDbDoc>;
        using MysqlxRowSharedPtr = std::shared_ptr<MysqlxRow>;

    public:
        explicit ResultRow(const ConfigurationStrategy& configurationStrategy);
        ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocSharedPtr& mysqlxDbDoc);
        ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowSharedPtr& mysqlxRow);

        CLASS_INVARIANT_DECLARE;

        void Print(std::ostream& os) const;

        NODISCARD int GetIntValue(int pos) const;
        NODISCARD uint32_t GetUIntValue(int pos) const;
        NODISCARD int64_t GetInt64Value(int pos) const;
        NODISCARD uint64_t GetUInt64Value(int pos) const;
        NODISCARD float GetFloatValue(int pos) const;
        NODISCARD double GetDoubleValue(int pos) const;
        NODISCARD bool GetBoolValue(int pos) const;
        NODISCARD std::string GetStringValue(int pos) const;
        NODISCARD std::wstring GetWStringValue(int pos) const;

        NODISCARD int GetColCount() const;

    private:
        PackageType impl;
    };

    DATABASE_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& out, const ResultRow& docResultRow);
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
