///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:19)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetVisibilityImpl final
    {
    public:
        using ClassType = QuerySheetVisibilityImpl;

    public:
        explicit QuerySheetVisibilityImpl(std::string sheetId) noexcept;
        QuerySheetVisibilityImpl(std::string sheetId, std::string sheetVisibility) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetVisibility() const;
        void SetSheetVisibility(const std::string& aSheetVisibility);

    private:
        std::string sheetId;
        std::string sheetVisibility;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H
