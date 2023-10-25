///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:48)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_POW3_H
#define CORE_TOOLS_TEMPLATE_TOOLS_POW3_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    // 主模板计算3 到 Nth
    template <int N>
    class Pow3
    {
    public:
        enum
        {
            Result = 3 * Pow3<N - 1>::Result
        };
    };

    // 完整的特化结束递归
    template <>
    class Pow3<0>
    {
    public:
        enum
        {
            Result = 1
        };
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_POW3_H
