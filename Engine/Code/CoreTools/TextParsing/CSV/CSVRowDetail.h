/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:26)

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

    for (const auto enumString = GetEnumStringArray(field);
         const auto& element : enumString)
    {
        result.emplace_back(StringCastEnum<E>(element));
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_DETAIL_H