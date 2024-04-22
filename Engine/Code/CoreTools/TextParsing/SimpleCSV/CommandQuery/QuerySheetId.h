/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:01)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetIdImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetIdImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetId final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetId);

    public:
        explicit QuerySheetId(const std::string& sheetName);
        QuerySheetId(const std::string& sheetName, const std::string& sheetId);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetName() const;
        NODISCARD std::string GetSheetId() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_H
