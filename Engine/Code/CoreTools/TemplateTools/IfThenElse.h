//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:19)

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
