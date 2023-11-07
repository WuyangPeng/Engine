///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:46)

#ifndef MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Base/BaseFwd.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    class Line2Circle2 final
    {
    public:
        using ClassType = Line2Circle2<Real>;

        using Parameter = std::array<Real, 2>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        Line2Circle2(const Vector2& origin, const Vector2& direction, const Vector2& center, Real radius);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetRootCount() const noexcept;
        NODISCARD Real GetParameter(int index) const;
        NODISCARD bool IsIntersects() const noexcept;

        void ClearParameter0() noexcept;

    private:
        void Find(const Vector2& origin, const Vector2& direction, const Vector2& center, Real radius);

    private:
        int rootCount;
        Parameter parameter;
        bool intersects;
    };
}

#endif  // MATHEMATICS_INTERSECTION_LINE2_CIRCLE2_H
