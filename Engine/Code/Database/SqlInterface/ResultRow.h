//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"

#include <string>

DATABASE_EXPORT_SHARED_PTR(ResultRowImpl);
EXPORT_NONCOPYABLE_CLASS(DATABASE);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ResultRow final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(ResultRow);

    public:
        explicit ResultRow(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void Print(std::ostream& os) const;

        [[nodiscard]] int GetIntValue(int pos) const;
        [[nodiscard]] uint32_t GetUIntValue(int pos) const;
        [[nodiscard]] int64_t GetInt64Value(int pos) const;
        [[nodiscard]] uint64_t GetUInt64Value(int pos) const;
        [[nodiscard]] float GetFloatValue(int pos) const;
        [[nodiscard]] double GetDoubleValue(int pos) const;
        [[nodiscard]] bool GetBoolValue(int pos) const;
        [[nodiscard]] std::string GetStringValue(int pos) const;
        [[nodiscard]] std::wstring GetWStringValue(int pos) const;

        [[nodiscard]] int GetColCount() const;

    private:
        IMPL_TYPE_DECLARE(ResultRow);

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    public:
        using MysqlxDbDocPtr = std::shared_ptr<MysqlxDbDoc>;
        using MysqlxRowPtr = std::shared_ptr<MysqlxRow>;

    public:
        ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc);
        ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow);
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
    };

    DATABASE_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& out, const ResultRow& docResultRow);
}

#endif  // DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
