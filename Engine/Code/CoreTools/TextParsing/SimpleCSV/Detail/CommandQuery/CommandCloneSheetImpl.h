///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:09)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CommandCloneSheetImpl final
        {
        public:
            using ClassType = CommandCloneSheetImpl;

        public:
            CommandCloneSheetImpl(const std::string& sheetID, const std::string& cloneName);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetCloneName() const;

        private:
            // 要克隆的工作表的ID
            std::string sheetID;

            // 要克隆的工作表的名字
            std::string cloneName;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H
