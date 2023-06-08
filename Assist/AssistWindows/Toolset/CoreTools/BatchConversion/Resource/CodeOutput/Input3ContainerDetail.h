/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#ifndef CSV_OUTPUT_INPUT3_CONTAINER_DETAIL_H
#define CSV_OUTPUT_INPUT3_CONTAINER_DETAIL_H

#include "Input3Container.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CsvOutput::Input3Container::ConstInput3BaseSharedPtr CsvOutput::Input3Container::GetFirstInput3(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(input3, function);

    if (iter != input3.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("input3表未找到满足条件的配置信息。"s))
}

template <typename Function>
CsvOutput::Input3Container::Container CsvOutput::Input3Container::GetInput3(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : input3)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // CSV_OUTPUT_INPUT3_CONTAINER_DETAIL_H
