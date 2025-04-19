/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:35)

#ifndef MATHEMATICS_QUERY_QUERY2_H
#define MATHEMATICS_QUERY_QUERY2_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query2 : public QueryBase
    {
    public:
        using ClassType = Query2<Real>;
        using ParentType = QueryBase;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using VerticesType = std::vector<Vector2Type>;

    public:
        // 基类处理浮点查询。
        explicit Query2(VerticesType vertices) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD QueryType GetType() const noexcept override;

        NODISCARD int GetNumVertices() const;
        NODISCARD Vector2Type GetVertex(int index) const;

        // 关于一个点的各种几何对象之间的关系查询。

        // 返回:
        //   LineQueryType::Right, 在线的右侧
        //   LineQueryType::Left, 在线的左侧
        //   LineQueryType::OnLine, 在线上
        NODISCARD virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual LineQueryType ToLine(const Vector2Type& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;

        // 返回:
        // TriangleQueryType::Outside, 在三角形外
        // TriangleQueryType::Inside, 在三角形内
        // TriangleQueryType::OnTriangle, 在三角形上
        NODISCARD virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual TriangleQueryType ToTriangle(const Vector2Type& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // 返回:
        // CircumcircleQueryType::Outside,在三角形的外接圆外
        // CircumcircleQueryType::Inside, 在三角形的外接圆内
        // CircumcircleQueryType::OnCircumcircle,在三角形的外接圆上
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        NODISCARD virtual CircumcircleQueryType ToCircumcircle(const Vector2Type& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // 输入点
        VerticesType vertices;
    };

    using Query2F = Query2<float>;
    using Query2D = Query2<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_H
