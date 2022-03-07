///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 16:30)

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
        using Vector2 = typename ParentType::Vector2;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 输入顶点的组成部分被截断为32位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        // 在Integer<N>的N的值被选择足够大，以便确保在函数中算术是正确的。
        explicit Query2Integer(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系的查询。
        NODISCARD LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD LineQueryType ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        NODISCARD CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD CircumcircleQueryType ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
    };

    using Query2IntegerF = Query2Integer<float>;
    using Query2IntegerD = Query2Integer<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INTEGER_H
