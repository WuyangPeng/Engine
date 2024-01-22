/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:44)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetVisibilityImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetVisibilityImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetVisibility final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetVisibility);

    public:
        explicit QuerySheetVisibility(const std::string& sheetId);
        QuerySheetVisibility(const std::string& sheetId, const std::string& sheetVisibility);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetVisibility() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_H
