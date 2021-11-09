///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/29 22:58)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetIndexImpl final
        {
        public:
            using ClassType = QuerySheetIndexImpl;

        public:
            explicit QuerySheetIndexImpl(const std::string& sheetID);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD int GetSheetIndex() const noexcept;
            void SetSheetIndex(int sheetIndex) noexcept;

        private:
            std::string sheetID;
            int m_sheetIndex;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H
