///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:09)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetTypeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetTypeImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE QuerySheetType final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetType);

        public:
            explicit QuerySheetType(const std::string& sheetID);
            QuerySheetType(const std::string& sheetID, ContentType sheetType);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD ContentType GetSheetType() const noexcept;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_H
