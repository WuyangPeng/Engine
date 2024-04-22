/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:46)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H

#include "CoreTools/CoreToolsDll.h"

#include "Tuple.h"

namespace CoreTools
{
    template <int Dimension, typename Type>
    class TupleLess final
    {
    public:
        using ClassType = TupleLess<Dimension, Type>;
        using Tuple = Tuple<Dimension, Type>;

    public:
        explicit TupleLess(int index) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator()(const Tuple& lhs, const Tuple& rhs) const;

    private:
        int index;
    };
}

#endif  // CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H