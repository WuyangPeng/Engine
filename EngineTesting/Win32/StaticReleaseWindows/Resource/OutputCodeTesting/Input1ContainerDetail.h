/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_DETAIL_H
#define OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_DETAIL_H

#include "Input1Container.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
OutputCSVTesting::Input1Container::ConstInput1SharedPtr OutputCSVTesting::Input1Container::GetFirstInput1(Function function) const
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
OutputCSVTesting::Input1Container::Container OutputCSVTesting::Input1Container::GetInput1(Function function) const
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

#endif  // OUTPUT_C_S_V_TESTING_INPUT1_CONTAINER_DETAIL_H
