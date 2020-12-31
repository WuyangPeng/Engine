///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 15:18)

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
        // 输入顶点的组成部分被表示完全相同有理数值。
        explicit Query2Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

          [[nodiscard]] QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系查询。

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
        // 缓存输入的有理数表示。浮点数的对有理数形式的转化是缓慢的， 所以最好是跟踪哪些值已转换。 
        Container m_RationalVertices;
    };

    using FloatQuery2Rational = Query2Rational<float>;
    using DoubleQuery2Rational = Query2Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_H
