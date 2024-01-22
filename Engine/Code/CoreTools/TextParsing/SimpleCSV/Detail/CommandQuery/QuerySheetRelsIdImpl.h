/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:45)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelsIdImpl final
    {
    public:
        using ClassType = QuerySheetRelsIdImpl;

    public:
        explicit QuerySheetRelsIdImpl(std::string sheetPath) noexcept;
        QuerySheetRelsIdImpl(std::string sheetPath, std::string sheetId) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetPath() const;
        NODISCARD std::string GetSheetId() const;
        void SetSheetId(const std::string& aSheetId);

    private:
        std::string sheetPath;
        std::string sheetId;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H
