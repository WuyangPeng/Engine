/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:54)

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
