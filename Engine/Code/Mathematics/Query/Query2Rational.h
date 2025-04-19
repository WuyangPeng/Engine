/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:38)

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
        // 输入顶点的组成部分被表示完全相同有理数值。
        explicit Query2Rational(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系查询。

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
        // 缓存输入的有理数表示。浮点数的对有理数形式的转化是缓慢的， 所以最好是跟踪哪些值已转换。
        Container rationalVertices;
    };

    using Query2RationalF = Query2Rational<float>;
    using Query2RationalD = Query2Rational<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_RATIONAL_H
