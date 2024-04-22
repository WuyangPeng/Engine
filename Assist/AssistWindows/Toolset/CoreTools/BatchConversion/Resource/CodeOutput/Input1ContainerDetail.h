/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef CSV_OUTPUT_INPUT1_CONTAINER_DETAIL_H
#define CSV_OUTPUT_INPUT1_CONTAINER_DETAIL_H

#include "Input1Container.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CsvOutput::Input1Container::ConstInput1SharedPtr CsvOutput::Input1Container::GetFirstInput1(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    if (const auto iter = std::ranges::find_if(input1, function);
        iter != input1.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("input1��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
CsvOutput::Input1Container::Container CsvOutput::Input1Container::GetInput1(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : input1)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // CSV_OUTPUT_INPUT1_CONTAINER_DETAIL_H