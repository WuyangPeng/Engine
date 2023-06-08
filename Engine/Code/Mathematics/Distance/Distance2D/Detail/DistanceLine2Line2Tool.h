///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:46)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceLine2Line2Tool final
    {
    public:
        using ClassType = DistanceLine2Line2Tool<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        DistanceLine2Line2Tool(const Vector2& lhsOrigin, const Vector2& lhsDirection, const Vector2& rhsOrigin, const Vector2& rhsDirection);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetDet() const noexcept;
        NODISCARD Real GetLhsT() const noexcept;
        NODISCARD Real GetRhsT() const noexcept;
        NODISCARD Real GetLhsT(Real extent) const noexcept;
        NODISCARD Real GetRhsT(Real extent) const noexcept;
        NODISCARD Real GetOriginDifferenceDotLhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceDotRhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceSquaredLength() const noexcept;
        NODISCARD Real GetDirectionDot() const noexcept;
        NODISCARD Real GetSquaredDistanceWithParallel() const noexcept;
        NODISCARD Real GetSquaredDistanceWithLhs() const noexcept;
        NODISCARD Real GetSquaredDistanceWithRhs() const noexcept;
        NODISCARD Real GetOriginDifferenceDotDirectionAverage() const noexcept;

    private:
        Vector2 originDifference;
        Real directionDot;
        Real originDifferenceDotLhsDirection;
        Real originDifferenceDotRhsDirection;
        Real originDifferenceSquaredLength;
        Real det;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
