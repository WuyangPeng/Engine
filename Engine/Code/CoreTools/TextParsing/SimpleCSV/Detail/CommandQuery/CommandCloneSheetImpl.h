/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:44)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandCloneSheetImpl final
    {
    public:
        using ClassType = CommandCloneSheetImpl;

    public:
        CommandCloneSheetImpl(std::string sheetId, std::string cloneName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD std::string GetCloneName() const;

    private:
        // 要克隆的工作表的ID
        std::string sheetId;

        // 要克隆的工作表的名字
        std::string cloneName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H
