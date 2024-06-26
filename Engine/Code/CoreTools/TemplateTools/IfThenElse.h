/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:16)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <bool Constant, typename Lhs, typename Rhs>
    class IfThenElse;

    template <typename Lhs, typename Rhs>
    class IfThenElse<true, Lhs, Rhs>
    {
    public:
        using ResultType = Lhs;
    };

    template <typename Lhs, typename Rhs>
    class IfThenElse<false, Lhs, Rhs>
    {
    public:
        using ResultType = Rhs;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H
