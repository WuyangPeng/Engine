///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:15)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetRelsIdImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetRelsIdImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetRelsId final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetRelsId);

    public:
        explicit QuerySheetRelsId(const std::string& sheetPath);
        QuerySheetRelsId(const std::string& sheetPath, const std::string& sheetId);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetPath() const;
        NODISCARD std::string GetSheetId() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_H
