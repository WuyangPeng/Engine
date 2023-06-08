///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:02)

#ifndef MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H
#define MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <vector>

namespace Mathematics
{
    class MATHEMATICS_HIDDEN_DECLARE QuerySortToolsImpl final
    {
    public:
        using ClassType = QuerySortToolsImpl;

    public:
        QuerySortToolsImpl(int value0, int value1);
        QuerySortToolsImpl(int value0, int value1, int value2);
        QuerySortToolsImpl(int value0, int value1, int value2, int value3);

        CLASS_INVARIANT_DECLARE;

        // 支持排序一组独特的索引到顶点池。
        // 输出这保证：v0 < v1 < v2。
        // 这是用来保证一致的查询时的原始顶点排序置换后，
        // 在使用必要的浮点运算时遭受数值舍入误差。
        // 输入索引被认为是正的排序。
        // 输出索引要么带正排序（排序期间发生偶数换位）
        // 或带负排序（排序期间发生奇数换位）。
        // 该函数返回排序的符号，“正”表示一个正的排序和“负”为负的排序。
        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD int GetValue(int index) const;

    private:
        using SortType = std::vector<int>;

    private:
        void SortValue2();
        void SortValue3();
        void SortValue4();

    private:
        SortType sortValue;
        NumericalValueSymbol symbol;
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H
