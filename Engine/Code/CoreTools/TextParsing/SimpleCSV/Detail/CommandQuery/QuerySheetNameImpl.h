///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 15:25)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetNameImpl final
    {
    public:
        using ClassType = QuerySheetNameImpl;

    public:
        explicit QuerySheetNameImpl(std::string sheetId) noexcept;
        QuerySheetNameImpl(std::string sheetId, std::string sheetName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetName() const;
        void SetSheetName(const std::string& aSheetName);

    private:
        std::string sheetId;
        std::string sheetName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_NAME_IMPL_H
