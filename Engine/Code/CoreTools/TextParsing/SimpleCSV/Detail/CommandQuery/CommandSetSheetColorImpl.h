///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:09)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_COLOR_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_COLOR_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CommandSetSheetColorImpl final
        {
        public:
            using ClassType = CommandSetSheetColorImpl;

        public:
            CommandSetSheetColorImpl(const std::string& sheetID, const std::string& sheetName, const std::string& sheetColor);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetName() const;
            NODISCARD std::string GetSheetColor() const;

        private:
            std::string sheetID;
            std::string sheetName;
            std::string sheetColor;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_COLOR_IMPL_H
