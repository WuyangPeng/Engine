///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 22:57)

#ifndef CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CommandAddWorksheetImpl final
        {
        public:
            using ClassType = CommandAddWorksheetImpl;

        public:
            CommandAddWorksheetImpl(const std::string& sheetName, const std::string& sheetPath);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetName() const;
            NODISCARD std::string GetSheetPath() const;

        private:
            std::string sheetName;
            std::string sheetPath;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_ADD_WORKSHEET_IMPL_H
