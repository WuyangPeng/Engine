///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 14:43)

#ifndef CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
#define CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <algorithm>
#include <vector>

namespace CoreTools
{
    template <typename T>
    T MaxElement(std::initializer_list<T> element)
    {
        std::vector<T> maxSize{ element };

        auto maxElement = std::max_element(maxSize.cbegin(), maxSize.cend());

        if (maxElement != maxSize.cend())
        {
            return *maxElement;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��ȡԪ�����ֵʧ�ܡ�"s));
        }
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
