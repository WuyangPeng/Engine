/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:38)

#ifndef MATHEMATICS_QUERY_QUERY2_RATIONAL_H
#define MATHEMATICS_QUERY_QUERY2_RATIONAL_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"
#include "Mathematics/Rational/RationalVector2.h"
#include "Mathematics/Rational/SignRational.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Rational : public Query2<Real>
    {
    public:
        using ClassType = Query2Rational<Real>;
        using ParentType = Query2<Real>;

        using MathType = typename ParentType::MathType;
        using Vector2 = typename ParentType::Vector2Type;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ���ʾ��ȫ��ͬ������ֵ��
        explicit Query2Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

        NODISCARD LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD LineQueryType ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        NODISCARD TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD TriangleQueryType ToTriangle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

        NODISCARD CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD CircumcircleQueryType ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

    private:
        using QueryRational = SignRational<4 * sizeof(Real)>;
        using QueryRationalVector = RationalVector2<4 * sizeof(Real)>;
        using Container = std::vector<QueryRationalVector>;

    private:
        void Convert();
        NODISCARD LineQueryType ToLine(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD TriangleQueryType ToTriangle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD CircumcircleQueryType ToCircumcircle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // �����������������ʾ���������Ķ���������ʽ��ת���ǻ����ģ� ��������Ǹ�����Щֵ��ת����
        Container rationalVertices;
    };

    using Query2RationalF = Query2Rational<float>;
    using Query2RationalD = Query2Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_H
