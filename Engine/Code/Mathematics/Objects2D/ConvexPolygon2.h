///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 11:07)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H

#include "Mathematics/MathematicsDll.h"

#include "Line2.h"
#include "Polygon2.h"
#include "Mathematics/Algebra/Vector2.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class ConvexPolygon2 final : public Polygon2<Real>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolygon2<Real>;
        using ParentType = Polygon2<Real>;
        using Line2 = Line2<Real>;
        using LineType = std::vector<Line2>;
        using Math = ParentType::Math;
        using Vector2 = ParentType::Vector2;
        using VerticesType = ParentType::VerticesType;
        using Vector2Tools = ParentType::Vector2Tools;

    public:
        // 调用方负责确保顶点数组表示凸多边形，且逆时针顺序。
        ConvexPolygon2(const VerticesType& vertices, const LineType& lines);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 只读成员访问。
        NODISCARD LineType GetLines() const;
        NODISCARD const Line2& GetLine(int index) const;

        // 允许顶点修改。调用者必须确保多边形仍是凸多边形。
        // 只要你修改尽可能多的顶点后，调用UpdateLines()。
        // 所有经由SetVertex的修改，UpdateLines中线的更新，只在修改的共享的顶点的边进行。
        void SetVertex(int index, const Vector2& vertex) override;
        void UpdateLines();
        NODISCARD bool IsUpdateLines() const noexcept;

        // 测试是否是凸多边形。
        // 这个函数将遍历该多边形的边和验证每个边的多边形的顶点都在边缘线的非负侧。
        // 符号距离测试时，这样一个顶点是一条线（用于凸）的反面时，
        // 其有符号的距离满足d < 0，数值舍入误差会产生不正确凸性测试，
        // 所以一个小的负阈值t可能通过该函数，
        // 在这种情况下，距离测试会变成d < t < 0。
        NODISCARD bool IsConvex(Real threshold = -Math::GetZeroTolerance()) const;

        // 点在多边形的测试，在点和边缘的线，在n个顶点之间边的查询执行，为O(n)算法。
        // 这不是最优算法。TODO：将二分搜索算法用于这个类。这是一个O(log n)的算法。
        NODISCARD bool Contains(const Vector2& point, Real threshold = -Math::GetZeroTolerance()) const;

    private:
        // 支持的边缘线的高效更新。
        // set存储那些修改共享顶点边的索引。
        void UpdateLine(int index, const Vector2& average);

    private:
        using SharingType = std::set<int>;

    private:
        // 线的数量是顶点的数量。
        LineType lines;

        // 要在UpdateLine处理的共享边
        SharingType sharingEdges;
    };

    using ConvexPolygon2F = ConvexPolygon2<float>;
    using ConvexPolygon2D = ConvexPolygon2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_H
