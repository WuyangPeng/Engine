/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:12)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class SimpleIncrementer final
    {
    public:
        using ClassType = SimpleIncrementer<T>;

        CLASS_INVARIANT_DECLARE;

    public:
        void operator()(T& value) noexcept;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H
