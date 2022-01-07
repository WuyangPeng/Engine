///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:21)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE QuerySheetTypeImpl final
        {
        public:
            using ClassType = QuerySheetTypeImpl;

        public:
            explicit QuerySheetTypeImpl(const std::string& sheetID);
            QuerySheetTypeImpl(const std::string& sheetID, ContentType sheetType);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetSheetID() const;
            NODISCARD ContentType GetSheetType() const noexcept;
            void SetSheetType(ContentType sheetType) noexcept;

        private:
            std::string sheetID;
            ContentType m_SheetType;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H
