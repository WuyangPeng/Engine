///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:10)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelsTargetImpl final
        {
        public:
            using ClassType = QuerySheetRelsTargetImpl;

        public:
            explicit QuerySheetRelsTargetImpl(const std::string& sheetID);
            QuerySheetRelsTargetImpl(const std::string& sheetID, const std::string& sheetTarget);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetTarget() const;
            void SetSheetTarget(const std::string& sheetTarget);

        private:
            std::string sheetID;
            std::string m_SheetTarget;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_TARGET_IMPL_H
