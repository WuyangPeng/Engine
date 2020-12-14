///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 14:35)

#ifndef MATHEMATICS_QUERY_QUERY2_FILTERED_H
#define MATHEMATICS_QUERY_QUERY2_FILTERED_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Query2Rational.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Filtered : public Query2<Real>
    {
    public:
        using ClassType = Query2Filtered<Real>;
        using ParentType = Query2<Real>;
        using Math = typename ParentType::Math;
        using Vector2D = typename ParentType::Vector2D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���ദ�����ѯ��ÿ����ѯ�漰����ʽ������бȽϡ�
        // ���������ʽ�㹻�ӽ��㣬��ֵ�������������ܻᵼ������ʽ���ű�������ࡣ
        // Ϊ�˱�������������ò�ѯ���ظ�ʹ��ȷ����������������
        // ��ͨ��'uncertainty'��ָ���ӽ��������[0, 1]��ֵ�л��������Ե�������
        // uncertaintyΪ0�ᵼ�������Ϊ�ͺ�������Query2��
        // uncertaintyΪ1�ᵼ�������Ϊ�ͺ�������Query2Rational��
        Query2Filtered(const VerticesType& vertices, Real uncertainty);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        [[nodiscard]] LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        [[nodiscard]] CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

    private:
        using Query2Rational = Query2Rational<Real>;

    private:
        Query2Rational m_RationalQuery;
        Real m_Uncertainty;
    };

    using FloatQuery2Filtered = Query2Filtered<float>;
    using DoubleQuery2Filtered = Query2Filtered<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_FILTERED_H
