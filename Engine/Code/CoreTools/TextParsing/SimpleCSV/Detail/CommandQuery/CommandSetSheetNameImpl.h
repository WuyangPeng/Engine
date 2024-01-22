/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:45)

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
