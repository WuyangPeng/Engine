/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 11:17)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H

#include "CSVRow.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename E>
requires(std::is_enum_v<E>)
E CoreTools::CSVRow::GetEnum(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return StringCastEnum<E>(GetEnumString(field));
}

template <typename E>
requires(std::is_enum_v<E>)
std::vector<E> CoreTools::CSVRow::GetEnumArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::vector<E> result{};

    for (const auto enumString = GetEnumStringArray(field);
         const auto& element : enumString)
    {
        result.emplace_back(StringCastEnum<E>(element));
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H