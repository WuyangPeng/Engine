///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/11/07 12:34)

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

    const auto enumString = GetEnumStringArray(field);

    for (const auto& value : enumString)
    {
        result.emplace_back(StringCastEnum<E>(value));
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H