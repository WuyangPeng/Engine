/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#ifndef OUTPUT_C_S_V_TESTING_INPUT2_CONTAINER_DETAIL_H
#define OUTPUT_C_S_V_TESTING_INPUT2_CONTAINER_DETAIL_H

#include "Input2Container.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
OutputCSVTesting::Input2Container::ConstInput2BaseSharedPtr OutputCSVTesting::Input2Container::GetFirstInput2(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::ranges::find_if(input2, function);

    if (iter != input2.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("input2��δ�ҵ�����������������Ϣ��"s))
}

template <typename Function>
OutputCSVTesting::Input2Container::Container OutputCSVTesting::Input2Container::GetInput2(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& element : input2)
    {
        if (function(element))
        {
            result.emplace_back(element);
        }
    }

    return result;
}

#endif  // OUTPUT_C_S_V_TESTING_INPUT2_CONTAINER_DETAIL_H
