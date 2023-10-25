///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:51)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetTypeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetTypeImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetType final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetType);

    public:
        explicit QuerySheetType(const std::string& sheetId);
        QuerySheetType(const std::string& sheetId, ContentType sheetType);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD ContentType GetSheetType() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H
