///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/23 10:13)

#ifndef CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
#define CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H

#include "CoreTools/CoreToolsDll.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <vector>
#include <algorithm>

namespace CoreTools
{
    template <typename T>
    T MaxElement(std::initializer_list<T> element)
    {
        std::vector<T> maxSize{ element };

        auto maxElement = std::max_element(maxSize.begin(), maxSize.end());

        if (maxElement != maxSize.cend())
        {
            return *maxElement;
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��ȡԪ�����ֵʧ�ܡ�"));
        }
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
