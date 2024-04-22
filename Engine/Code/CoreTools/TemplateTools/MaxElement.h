/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:16)

#ifndef CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
#define CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExceptionMacro.h"

#include <algorithm>
#include <vector>

namespace CoreTools
{
    template <typename T>
    NODISCARD T MaxElement(std::initializer_list<T> element)
    {
        std::vector<T> maxSize{ element };

        const auto maxElement = std::ranges::max_element(maxSize);

        if (maxElement != maxSize.cend())
        {
            return *maxElement;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��ȡԪ�����ֵʧ�ܡ�"s))
        }
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
