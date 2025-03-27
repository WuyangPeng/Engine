///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:45)

#ifndef MATHEMATICS_INTERSECTION_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
    template <typename Real>
    class Line2Box2 final
    {
    public:
        using ClassType = Line2Box2<Real>;

        using MathType = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;
        using Parameter = std::array<Vector2, 2>;
        using Box2 = Box2<Real>;

    public:
        Line2Box2(Real t0, Real t1, const Vector2& origin, const Vector2& direction, const Box2& box, bool solid);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetRootCount() const noexcept;
        NODISCARD Vector2 GetParameter(int index) const;
        NODISCARD IntersectionType GetIntersects() const noexcept;

    private:
        void DoClipping(Real t0, Real t1, const Vector2& origin, const Vector2& direction, const Box2& box, bool solid);

        struct ClipType final
        {
            Real t0;
            Real t1;
            bool result;

            ClipType(Real t0, Real t1) noexcept;
        };

        NODISCARD static ClipType Clip(Real denom, Real numer, const ClipType& clipType) noexcept;

    private:
        int rootCount;
        Parameter parameter;
        IntersectionType intersectionType;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_BOX2_H
