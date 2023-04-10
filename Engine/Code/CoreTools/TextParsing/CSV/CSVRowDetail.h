///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 19:58)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H

#include "CSVRow.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename E>
E CoreTools::CSVRow::GetEnum(const String& field) const
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return StringCastEnum<E>(GetEnumString(field));
}

template <typename E>
std::vector<E> CoreTools::CSVRow::GetEnumArray(const String& field) const
{
    static_assert(std::is_enum_v<E>, "E must be an enum.");

    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::vector<E> result{};

    for (const auto enumString = GetEnumStringArray(field); const auto& value : enumString)
    {
        result.emplace_back(StringCastEnum<E>(value));
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H