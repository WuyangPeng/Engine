///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 22:59)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetRelsIDImpl final
        {
        public:
            using ClassType = QuerySheetRelsIDImpl;

        public:
            explicit QuerySheetRelsIDImpl(const std::string& sheetPath);
            QuerySheetRelsIDImpl(const std::string& sheetPath, const std::string& sheetID);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetPath() const;
            NODISCARD std::string GetSheetID() const;
            void SetSheetID(const std::string& sheetID);

        private:
            std::string sheetPath;
            std::string m_SheetID;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_RELS_ID_IMPL_H
