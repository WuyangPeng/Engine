///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 14:35)

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
        // 基类处理浮点查询。每个查询涉及行列式和零进行比较。
        // 如果该行列式足够接近零，数值四舍五入误差可能会导致行列式符号被错误分类。
        // 为了避免这种情况，该查询被重复使用确切有理数的算术。
        // 您通过'uncertainty'，指定接近零的区间[0, 1]的值切换到有理性的算术。
        // uncertainty为0会导致类的行为就好像它是Query2。
        // uncertainty为1会导致类的行为就好像它是Query2Rational。
        Query2Filtered(const VerticesType& vertices, Real uncertainty);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系查询。

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
