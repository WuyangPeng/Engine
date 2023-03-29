///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 15:20)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE QuerySheetIndexImpl final
    {
    public:
        using ClassType = QuerySheetIndexImpl;

    public:
        explicit QuerySheetIndexImpl(std::string sheetId) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetSheetId() const;
        NODISCARD int GetSheetIndex() const noexcept;
        void SetSheetIndex(int aSheetIndex) noexcept;

    private:
        std::string sheetId;
        int sheetIndex;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHEET_INDEX_IMPL_H
