///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/18 21:26)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H

#include "CSVRowImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
T CoreTools::CSVRowImpl::GetValue(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = rowType.find(field);
    if (iter != rowType.cend())
    {
        const auto& result = iter->second;
        if (!result.empty())
        {
            return boost::lexical_cast<T>(result);
        }
    }

    return T{};
}

template <typename T>
std::vector<T> CoreTools::CSVRowImpl::GetValueArray(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    std::vector<T> result{};

    const auto column = GetArrayType(field);

    for (const auto& value : column)
    {
        if (value.empty())
        {
            result.emplace_back(T{});
        }
        else
        {
            result.emplace_back(boost::lexical_cast<T>(value));
        }
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H