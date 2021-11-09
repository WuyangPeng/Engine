///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 22:58)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CommandSetSheetVisibilityImpl final
        {
        public:
            using ClassType = CommandSetSheetVisibilityImpl;

        public:
            CommandSetSheetVisibilityImpl(const std::string& sheetID, const std::string& sheetName, const std::string& sheetVisibility);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetName() const;
            NODISCARD std::string GetSheetVisibility() const;

        private:
            std::string sheetID;
            std::string sheetName;
            std::string sheetVisibility;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_SET_SHEET_VISIBILITY_IMPL_H
