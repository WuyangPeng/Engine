///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 15:04)

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
        // Ҫ��¡�Ĺ������ID
        std::string sheetId;

        // Ҫ��¡�Ĺ����������
        std::string cloneName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_COMMAND_CLONE_SHEET_IMPL_H
