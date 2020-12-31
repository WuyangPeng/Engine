///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/21 16:26)

#ifndef MATHEMATICS_INTERSECTION_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Line2Box2 final
    {
    public:
        using ClassType = Line2Box2<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Parameter = std::array<Vector2D, 2>;
        using Box2 = Box2<Real>;

    public:
        Line2Box2(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box, bool solid);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetRootCount() const noexcept;
        [[nodiscard]] Vector2D GetParameter(int index) const;
        [[nodiscard]] IntersectionType GetIntersects() const noexcept;

    private:
        void DoClipping(Real t0, Real t1, const Vector2D& origin, const Vector2D& direction, const Box2& box, bool solid);

        struct ClipType final
        {
            Real m_T0;
            Real m_T1;
            bool m_Result;

            ClipType(Real t0, Real t1) noexcept;
        };

        [[nodiscard]] static ClipType Clip(Real denom, Real numer, const ClipType& clipType) noexcept;

    private:
        int m_RootCount;
        Parameter m_Parameter;
        IntersectionType m_IntersectionType;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_BOX2_H
