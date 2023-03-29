///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 15:08)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandSetSheetVisibilityImpl final
    {
    public:
        using ClassType = CommandSetSheetVisibilityImpl;

    public:
        CommandSetSheetVisibilityImpl(std::string sheetId, std::string sheetName, std::string sheetVisibility) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetName() const;
        NODISCARD std::string GetSheetVisibility() const;

    private:
        std::string sheetId;
        std::string sheetName;
        std::string sheetVisibility;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H
