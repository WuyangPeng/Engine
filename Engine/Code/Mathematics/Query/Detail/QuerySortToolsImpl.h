// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:33)

#ifndef MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H
#define MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Flags/NumericalValueSymbol.h" 

#include <vector>

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE QuerySortToolsImpl
    {
    public:
		using ClassType = QuerySortToolsImpl;

	public:
		QuerySortToolsImpl(int firstValue, int secondValue);
		QuerySortToolsImpl(int firstValue, int secondValue,int thirdValue);
		QuerySortToolsImpl(int firstValue, int secondValue,int thirdValue,int fourthValue);

		CLASS_INVARIANT_DECLARE;
        
        // 支持排序一组独特的索引到顶点池。
        // 输出这保证：v0 < v1 < v2。
        // 这是用来保证一致的查询时的原始顶点排序置换后，
        // 在使用必要的浮点运算时遭受数值舍入误差。
        // 输入索引被认为是正的排序。
        // 输出索引要么带正排序（排序期间发生偶数换位）
        // 或带负排序（排序期间发生奇数换位）。
        // 该函数返回排序的符号，“正”表示一个正的排序和“负”为负的排序。
		NumericalValueSymbol GetSymbol() const;
		int GetValue(int index) const;

	private:
		void SortTwoValue();
		void SortThreeValue();
		void SortFourValue();
        
	private:
		std::vector<int> m_SortValue;
		NumericalValueSymbol m_Symbol;
    };
}

#endif // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H
