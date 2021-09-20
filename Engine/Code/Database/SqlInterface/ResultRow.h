//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:02)

#ifndef DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H
#define DATABASE_SQL_INTERFACE_DOC_RESULT_ROW_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <string>

DATABASE_NON_COPY_EXPORT_IMPL(ResultRowImpl);
 

namespace Database
{
    class DATABASE_DEFAULT_DECLARE ResultRow final 
    {
    public:
        NON_COPY_TYPE_DECLARE(ResultRow);

    public:
        explicit ResultRow(const ConfigurationStrategy& configurationStrategy);
        ~ResultRow() noexcept = default;
        ResultRow(const ResultRow& rhs) noexcept = delete;
        ResultRow& operator=(const ResultRow& rhs) noexcept = delete;
        ResultRow(ResultRow&& rhs) noexcept = delete;
        ResultRow& operator=(ResultRow&& rhs) noexcept = delete;

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
        PackageType impl;

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
