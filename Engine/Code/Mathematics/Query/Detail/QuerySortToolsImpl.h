///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 15:55)

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

        // ֧������һ����ص�����������ء�
        // ����Ᵽ֤��v0 < v1 < v2��
        // ����������֤һ�µĲ�ѯʱ��ԭʼ���������û���
        // ��ʹ�ñ�Ҫ�ĸ�������ʱ������ֵ������
        // ������������Ϊ����������
        // �������Ҫô�������������ڼ䷢��ż����λ��
        // ��������������ڼ䷢��������λ����
        // �ú�����������ķ��ţ���������ʾһ����������͡�����Ϊ��������
        NODISCARD NumericalValueSymbol GetSymbol() const noexcept;
        NODISCARD int GetValue(int index) const;

    private:
        using SortType = std::vector<int>;

    private:
        void SortValue2();
        void SortValue3();
        void SortValue4();

    private:
        SortType m_SortValue;
        NumericalValueSymbol m_Symbol;
    };
}

#endif  // MATHEMATICS_QUERY_QUERY_SORT_TOOLS_IMPL_H
