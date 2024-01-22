/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:37)

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
        using Vector2 = typename ParentType::Vector2;
        using VerticesType = typename ParentType::VerticesType;

    public:
        // 输入顶点的组成部分被截断为64位整数，
        // 所以你应该确保顶点是足够大的分配好的数值。
        explicit Query2Int64(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 运行时类型信息。
        NODISCARD QueryType GetType() const noexcept override;

        // 关于一个点的各种几何对象之间的关系的查询。
        NODISCARD LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD LineQueryType ToLine(const Vector2& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const override;

        NODISCARD CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
        NODISCARD CircumcircleQueryType ToCircumcircle(const Vector2& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const override;
    };

    using Query2Int64F = Query2Int64<float>;
    using Query2Int64D = Query2Int64<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_INT64_H
