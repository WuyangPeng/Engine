/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 17:54)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_TARGET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_TARGET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelationshipTargetImpl final
    {
    public:
        using ClassType = QuerySheetRelationshipTargetImpl;

    public:
        explicit QuerySheetRelationshipTargetImpl(std::string sheetId) noexcept;
        QuerySheetRelationshipTargetImpl(std::string sheetId, std::string sheetTarget) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetTarget() const;
        void SetSheetTarget(const std::string& aSheetTarget);

    private:
        std::string sheetId;
        std::string sheetTarget;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_TARGET_IMPL_H
