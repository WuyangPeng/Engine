/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 14:16)

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
