//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:19)

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
