///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:48)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceLine3Line3Tool final
    {
    public:
        using ClassType = DistanceLine3Line3Tool<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = Math<Real>;

    public:
        DistanceLine3Line3Tool(const Vector3& lhsOrigin, const Vector3& lhsDirection, const Vector3& rhsOrigin, const Vector3& rhsDirection);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetDet() const noexcept;
        NODISCARD Real GetLhsT() const noexcept;
        NODISCARD Real GetRhsT() const noexcept;
        NODISCARD Real GetOriginDifferenceDotLhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceDotRhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceSquaredLength() const noexcept;
        NODISCARD Real GetDirectionDot() const noexcept;

        NODISCARD Real GetLhsT(Real extent) const noexcept;
        NODISCARD Real GetRhsT(Real extent) const noexcept;
        NODISCARD Real GetSquaredDistanceWithParallel() const noexcept;
        NODISCARD Real GetSquaredDistanceWithLhs() const noexcept;
        NODISCARD Real GetSquaredDistanceWithRhs() const noexcept;
        NODISCARD Real GetOriginDifferenceDotDirectionAverage() const noexcept;

    private:
        Vector3 originDifference;
        Real directionDot;
        Real originDifferenceDotLhsDirection;
        Real originDifferenceDotRhsDirection;
        Real originDifferenceSquaredLength;
        Real det;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
