/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 11:19)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H
#define CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H

#include "CSVRowImpl.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename T>
T CoreTools::CSVRowImpl::GetValue(const String& field) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = rowType.find(field);
        iter != rowType.cend())
    {
        if (const auto& result = iter->second;
            !result.empty())
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

    for (const auto column = GetArrayType(field);
         const auto& element : column)
    {
        if (element.empty())
        {
            result.emplace_back(T{});
        }
        else
        {
            result.emplace_back(boost::lexical_cast<T>(element));
        }
    }

    return result;
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_ROW_IMPL_DETAIL_H