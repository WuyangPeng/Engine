/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:43)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySheetIndexImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySheetIndexImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySheetIndex final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySheetIndex);

    public:
        explicit QuerySheetIndex(const std::string& sheetId);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD int GetSheetIndex() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_H
