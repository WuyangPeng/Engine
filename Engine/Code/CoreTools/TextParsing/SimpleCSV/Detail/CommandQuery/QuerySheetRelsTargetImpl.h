///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 14:53)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelsTargetImpl final
    {
    public:
        using ClassType = QuerySheetRelsTargetImpl;

    public:
        explicit QuerySheetRelsTargetImpl(std::string sheetId) noexcept;
        QuerySheetRelsTargetImpl(std::string sheetId, std::string sheetTarget) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetTarget() const;
        void SetSheetTarget(const std::string& aSheetTarget);

    private:
        std::string sheetId;
        std::string sheetTarget;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H
