/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:16)

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
            THROW_EXCEPTION(SYSTEM_TEXT("获取元素最大值失败。"s))
        }
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_MAX_ELEMENT_H
