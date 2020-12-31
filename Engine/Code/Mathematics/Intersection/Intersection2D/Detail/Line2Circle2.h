///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 15:45)

#ifndef MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Line2Circle2 final
    {
    public:
        using ClassType = Line2Circle2<Real>;
        using Parameter = std::array<Real, 2>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        Line2Circle2(const Vector2D& origin, const Vector2D& direction, const Vector2D& center, Real radius);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetRootCount() const noexcept;
        [[nodiscard]] Real GetParameter(int index) const;
        [[nodiscard]] bool IsIntersects() const noexcept;

        void ClearParameter0() noexcept;

    private:
        void Find(const Vector2D& origin, const Vector2D& direction, const Vector2D& center, Real radius);

    private:
        int m_RootCount;
        Parameter m_Parameter;
        bool m_Intersects;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H
