// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/10 09:33)

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
        
        // ֧������һ����ص�����������ء�
        // ����Ᵽ֤��v0 < v1 < v2��
        // ����������֤һ�µĲ�ѯʱ��ԭʼ���������û���
        // ��ʹ�ñ�Ҫ�ĸ�������ʱ������ֵ������
        // ������������Ϊ����������
        // �������Ҫô�������������ڼ䷢��ż����λ��
        // ��������������ڼ䷢��������λ����
        // �ú�����������ķ��ţ���������ʾһ����������͡�����Ϊ��������
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
