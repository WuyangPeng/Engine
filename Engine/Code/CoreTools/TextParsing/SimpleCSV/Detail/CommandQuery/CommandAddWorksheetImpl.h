///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:52)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CommandAddWorksheetImpl final
    {
    public:
        using ClassType = CommandAddWorksheetImpl;

    public:
        CommandAddWorksheetImpl(std::string sheetName, std::string sheetPath) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetName() const;
        NODISCARD std::string GetSheetPath() const;

    private:
        std::string sheetName;
        std::string sheetPath;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H
