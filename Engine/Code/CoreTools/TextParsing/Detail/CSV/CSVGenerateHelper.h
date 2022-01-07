///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 11:50)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H
#define CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/Flags/CSVFlags.h"

namespace CoreTools
{
    NODISCARD constexpr CSVPoistionType GetPoistionType(int index, int size) noexcept
    {
        if (index == 0)
        {
            return CSVPoistionType::Begin;
        }
        else if (index == (size - 1))
        {
            return CSVPoistionType::End;
        }
        else
        {
            return CSVPoistionType::Middle;
        }
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_GENERATE_HELPER_H