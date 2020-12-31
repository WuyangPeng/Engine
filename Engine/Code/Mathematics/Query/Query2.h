///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/11/30 13:18)

#ifndef MATHEMATICS_QUERY_QUERY2_H
#define MATHEMATICS_QUERY_QUERY2_H

#include "Mathematics/MathematicsDll.h"

#include "QueryBase.h"
#include "Mathematics/Algebra/Vector2D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Query2 : public QueryBase
    {
    public:
        using ClassType = Query2<Real>;
        using ParentType = QueryBase;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using VerticesType = std::vector<Vector2D>;

    public:
        // 基类处理浮点查询。
        explicit Query2(const VerticesType& vertices);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] QueryType GetType() const noexcept override;

        [[nodiscard]] int GetNumVertices() const;
        [[nodiscard]] const Vector2D GetVertice(int index) const;

        // 关于一个点的各种几何对象之间的关系查询。

        // 返回:
        //   LineQueryType::Right, 在线的右侧
        //   LineQueryType::Left, 在线的左侧
        //   LineQueryType::OnLine, 在线上
        [[nodiscard]] virtual LineQueryType ToLine(int index, int lhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual LineQueryType ToLine(const Vector2D& testVector, int lhsVerticesIndex, int rhsVerticesIndex) const;

        // 返回:
        // TriangleQueryType::Outside, 在三角形外
        // TriangleQueryType::Inside, 在三角形内
        // TriangleQueryType::OnTriangle, 在三角形上
        [[nodiscard]] virtual TriangleQueryType ToTriangle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual TriangleQueryType ToTriangle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

        // 返回:
        // CircumcircleQueryType::Outside,在三角形的外接圆外
        // CircumcircleQueryType::Inside, 在三角形的外接圆内
        // CircumcircleQueryType::OnCircumcircle,在三角形的外接圆上
        [[nodiscard]] virtual CircumcircleQueryType ToCircumcircle(int index, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;
        [[nodiscard]] virtual CircumcircleQueryType ToCircumcircle(const Vector2D& testVector, int lhsVerticesIndex, int mhsVerticesIndex, int rhsVerticesIndex) const;

    private:
        // 输入点
        VerticesType m_Vertices;
    };

    using FloatQuery2 = Query2<float>;
    using DoubleQuery2 = Query2<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY2_H
