/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:58)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_DELETE_SHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_DELETE_SHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandDeleteSheetImpl final
    {
    public:
        using ClassType = CommandDeleteSheetImpl;

    public:
        CommandDeleteSheetImpl(std::string sheetId, std::string sheetName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetSheetName() const;

    private:
        std::string sheetId;
        std::string sheetName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_DELETE_SHEET_IMPL_H
