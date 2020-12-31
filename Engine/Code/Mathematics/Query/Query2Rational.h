///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 15:18)

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
        using Math = typename ParentType::Math;
        using Vector2D = typename ParentType::Vector2D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // ���붥�����ɲ��ֱ���ʾ��ȫ��ͬ������ֵ��
        explicit Query2Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

          [[nodiscard]] QueryType GetType() const noexcept override;

        // ����һ����ĸ��ּ��ζ���֮��Ĺ�ϵ��ѯ��

           [[nodiscard]] LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
          [[nodiscard]] LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

           [[nodiscard]] TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
          [[nodiscard]] TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

           [[nodiscard]] CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
          [[nodiscard]] CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;

    private:
        using QueryRational = SignRational<4 * sizeof(Real)>;
        using QueryRationalVector = RationalVector2<4 * sizeof(Real)>;
        using Container = std::vector<QueryRationalVector>;

    private:
        void Convert();
        [[nodiscard]] LineQueryType ToLine(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] TriangleQueryType ToTriangle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] CircumcircleQueryType ToCircumcircle(const QueryRationalVector& rationalTest, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // �����������������ʾ���������Ķ���������ʽ��ת���ǻ����ģ� ��������Ǹ�����Щֵ��ת���� 
        Container m_RationalVertices;
    };

    using FloatQuery2Rational = Query2Rational<float>;
    using DoubleQuery2Rational = Query2Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_H
