///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:05)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE ConvexPolygon2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolygon2Impl<Real>;
        using Line2 = Line2<Real>;
        using LineType = std::vector<Line2>;
        using LineTypeConstIter = typename LineType::const_iterator;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // 调用方负责确保顶点数组表示凸多边形，且逆时针顺序。
        explicit ConvexPolygon2Impl(const LineType& lines);

        CLASS_INVARIANT_DECLARE;

        // 只读成员访问。
        [[nodiscard]] const LineType GetLines() const;
        [[nodiscard]] const Line2& GetLine(int index) const;
        [[nodiscard]] int GetNumLine() const;

        void SetVertex(int index);
        [[nodiscard]] bool IsUpdateLines() const noexcept;
        void ClearSharingEdges() noexcept;
        void UpdateLine(int index, const Vector2D& origin, const Vector2D& direction);

        LineTypeConstIter begin() const noexcept;
        LineTypeConstIter end() const noexcept;

    private:
        using SharingType = std::set<int>;

    private:
        // 线的数量是顶点的数量。
        LineType m_Lines;

        // 要在UpdateLine处理的共享边
        SharingType m_SharingEdges;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_IMPL_H
