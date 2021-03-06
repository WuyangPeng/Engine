///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 14:57)

#ifndef MATHEMATICS_QUERY_QUERY2_INT64_H
#define MATHEMATICS_QUERY_QUERY2_INT64_H

#include "Mathematics/MathematicsDll.h"

#include "Query2.h"

namespace Mathematics
{
    template <typename Real>
    class Query2Int64 : public Query2<Real>
    {
    public:
        using ClassType = Query2Int64<Real>;
        using ParentType = Query2<Real>;
        using Math = typename ParentType::Math;
        using Vector2D = typename ParentType::Vector2D;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 输入顶点的组成部分被截断为64位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        explicit Query2Int64(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 运行时类型信息。
        [[nodiscard]] QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系的查询。
        [[nodiscard]] LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        [[nodiscard]] CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        [[nodiscard]] CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
    };

    using FloatQuery2Int64 = Query2Int64<float>;
    using DoubleQuery2Int64 = Query2Int64<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INT64_H
