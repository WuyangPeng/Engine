///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 14:36)

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