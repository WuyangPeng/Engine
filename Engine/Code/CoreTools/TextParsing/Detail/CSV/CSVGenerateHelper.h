///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 14:15)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Flags/CSVFlags.h"

namespace CoreTools
{
    NODISCARD constexpr CSVPositionType GetPositionType(const int index, const int size) noexcept
    {
        if (index == 0)
        {
            return CSVPositionType::Begin;
        }
        else if (index == (size - 1))
        {
            return CSVPositionType::End;
        }
        else
        {
            return CSVPositionType::Middle;
        }
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H