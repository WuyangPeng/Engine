/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 17:57)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelationshipIdImpl final
    {
    public:
        using ClassType = QuerySheetRelationshipIdImpl;

    public:
        explicit QuerySheetRelationshipIdImpl(std::string sheetPath) noexcept;
        QuerySheetRelationshipIdImpl(std::string sheetPath, std::string sheetId) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetPath() const;
        NODISCARD std::string GetSheetId() const;
        void SetSheetId(const std::string& aSheetId);

    private:
        std::string sheetPath;
        std::string sheetId;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELATIONSHIP_ID_IMPL_H
