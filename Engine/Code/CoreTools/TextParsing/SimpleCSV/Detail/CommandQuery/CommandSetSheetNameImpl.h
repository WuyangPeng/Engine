///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:19)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_NAME_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_NAME_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandSetSheetNameImpl final
    {
    public:
        using ClassType = CommandSetSheetNameImpl;

    public:
        CommandSetSheetNameImpl(std::string sheetId, std::string sheetName, std::string newName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetName() const;
        NODISCARD std::string GetNewName() const;

    private:
        std::string sheetId;
        std::string sheetName;
        std::string newName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_NAME_IMPL_H
