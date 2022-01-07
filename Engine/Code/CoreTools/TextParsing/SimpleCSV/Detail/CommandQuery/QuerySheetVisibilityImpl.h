///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:22)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetVisibilityImpl final
        {
        public:
            using ClassType = QuerySheetVisibilityImpl;

        public:
            explicit QuerySheetVisibilityImpl(const std::string& sheetID);
            QuerySheetVisibilityImpl(const std::string& sheetID, const std::string& sheetVisibility);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD std::string GetSheetVisibility() const;
            void SetSheetVisibility(const std::string& sheetVisibility);

        private:
            std::string sheetID;
            std::string m_SheetVisibility;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_VISIBILITY_IMPL_H
