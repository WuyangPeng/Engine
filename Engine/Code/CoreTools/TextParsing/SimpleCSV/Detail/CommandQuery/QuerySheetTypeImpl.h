///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 15:51)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetTypeImpl final
    {
    public:
        using ClassType = QuerySheetTypeImpl;

    public:
        explicit QuerySheetTypeImpl(std::string sheetId) noexcept;
        QuerySheetTypeImpl(std::string sheetId, ContentType sheetType) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD ContentType GetSheetType() const noexcept;
        void SetSheetType(ContentType aSheetType) noexcept;

    private:
        std::string sheetId;
        ContentType sheetType;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_TYPE_IMPL_H
