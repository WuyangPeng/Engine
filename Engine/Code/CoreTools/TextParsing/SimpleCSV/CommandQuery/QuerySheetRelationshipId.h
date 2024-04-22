/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 18:00)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetRelationshipIdImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetRelationshipId final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetRelationshipId);

    public:
        explicit QuerySheetRelationshipId(const std::string& sheetPath);
        QuerySheetRelationshipId(const std::string& sheetPath, const std::string& sheetId);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetPath() const;
        NODISCARD std::string GetSheetId() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_H
