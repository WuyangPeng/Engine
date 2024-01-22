/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class SimpleDecrementer final
    {
    public:
        using ClassType = SimpleDecrementer<T>;

        CLASS_INVARIANT_DECLARE;

    public:
        void operator()(T& value) noexcept;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H
