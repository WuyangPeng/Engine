///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 15:09)

#ifndef MATHEMATICS_QUERY_QUERY2_INTEGER_H
#define MATHEMATICS_QUERY_QUERY2_INTEGER_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Mathematics/Rational/Integer.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Integer : public Query2<Real>
    {
    public:
        using ClassType = Query2Integer<Real>;
        using ParentType = Query2<Real>;
        using Math = typename ParentType::Math;
        using Vector2D = typename ParentType::Vector2D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ��ض�Ϊ32λ������
        // ������Ӧ��ȷ���������㹻��ķ���õ���ֵ��
        // ��Integer<N>��N��ֵ��ѡ���㹻���Ա�ȷ���ں�������������ȷ�ġ�
        explicit Query2Integer(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ�Ĳ�ѯ��
        [[nodiscard]] LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        [[nodiscard]] CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
    };

    using FloatQuery2Integer = Query2Integer<float>;
    using DoubleQuery2Integer = Query2Integer<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INTEGER_H
