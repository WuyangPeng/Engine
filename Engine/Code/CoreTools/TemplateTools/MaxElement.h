///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/23 10:13)

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
            THROW_EXCEPTION(SYSTEM_TEXT("获取元素最大值失败。"));
        }
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
