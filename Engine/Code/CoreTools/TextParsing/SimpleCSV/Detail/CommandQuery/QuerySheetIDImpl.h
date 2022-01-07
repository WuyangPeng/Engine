///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:10)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetIDImpl final
        {
        public:
            using ClassType = QuerySheetIDImpl;

        public:
            explicit QuerySheetIDImpl(const std::string& sheetName);
            QuerySheetIDImpl(const std::string& sheetName, const std::string& sheetID);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetName() const;
            NODISCARD std::string GetSheetID() const;
            void SetSheetID(const std::string& sheetID);

        private:
            std::string sheetName;
            std::string m_SheetID;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_ID_IMPL_H
